#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Complex{
private:
        double img;
        double real;
public:
        Complex()=default;
        Complex(double r, double i){
            img = i;
            real = r;
        }

        Complex(const Complex& c){
            img = c.img;
            real = c.real;
        }

        void printComplex(){
            cout<<real<<" + "<<img<<"i"<<endl;
        }

        void setImg(double i){ img = i;}
        void setReal(double r){ real = r;}

        double getImg(){return img;}
        double getReal(){ return real; }


        friend istream &operator >>(istream &in , Complex &c){


            cout<<"Enter the imaginary part: ";
            in >>c.img;
            cout<<"Enter the real part: ";
            in >>c.real;

            return in;
        }

        friend ostream& operator <<(ostream& os, Complex& c){
            os<<c.getReal()<<" + "<<c.getImg()<<"i";
            return os;
        }

        Complex operator+(Complex& c){
            Complex res;
            res.setImg(img+c.getImg());
            res.setReal(real+c.getReal());
            return res;
        }


        Complex operator-(Complex& c){
            Complex res;
            res.setImg(img-c.getImg());
            res.setReal(real-c.getReal());
            return res;
        }


        Complex operator*(Complex& c){

            double resreal = real*c.getReal() - img*c.getImg();
            double resimg = real*c.getImg() + img*c.getReal();
            Complex res(resreal,resimg);
            return res;
        }

        Complex operator/(Complex& c){
            double resimg;
            double resreal;

            resreal = (real*c.getReal() + img*getImg())/(pow(c.getImg(),2)+pow(c.getReal(),2));
            resimg = (img*c.getReal() - real*c.getImg())/(pow(c.getImg(),2)+pow(c.getReal(),2));

            Complex res(resreal,resimg);
            return res;
        }

        void complexModulus(){
            double res = sqrt(pow(img,2)+ pow(real,2));
            cout<<"|Z|= "<<res<<endl;
        }





};


int main()
{
    cout<<"==========={CREATED BY ELHIZABRI MAROUANE (AKA Floksy)}==========="<<endl;
    Complex c(1,2);
    Complex t;
    cin>>t;
    cout << "The complex object is ";
    cout<<t<<endl;
    cout<<c<<endl;
    c.complexModulus();
    Complex cc(2,2);

    cout<<"Addition: "<<endl;
    Complex c2= cc +c;
    cout<<"("<<cc<<") + ("<<c<<") = "<<c2<<endl;


    cout<<"division: "<<endl;
    Complex c3 = cc/c;
    cout<<"("<<cc<<") / ("<<c<<") = "<<c3<<endl;

    cout<<"Multiplication: "<<endl;
    Complex c4(1,3);
    Complex c5(3,-7);
    Complex c6 = c5*c4;
    cout<<"("<<c4<<") * ("<<c5<<") = "<<c6<<endl;

    cout<<"Subtraction: "<<endl;
    Complex c7(-5,1);
    Complex c8(-4,-6);
    Complex c9 = c7 - c8;
    cout<<"("<<c7<<") - ("<<c8<<") = "<<c9<<endl;



    return 0;
}
