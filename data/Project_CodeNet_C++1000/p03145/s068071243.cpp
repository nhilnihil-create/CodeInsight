#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    cin>>a>>b>>c;
    if(a>b && a>c){
            a=(c*b)/2;
            cout<<a;
    }
    if(b>a && b>c){
            b=(a*c)/2;
            cout<<b;
    }
    if(c>a && c>b){
            c=(a*b)/2;
            cout<<c;
    }
    return 0;
}
