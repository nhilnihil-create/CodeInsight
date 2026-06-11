#include<iostream>
using namespace std;
int main(){
     int A,B,a,b;
     cin>>a>>b;
     A=a+b;
     B=a*b;
     if(A==15)cout<<"+"<<endl;
     else if(B==15)cout<<"*"<<endl;
     else cout<<"x"<<endl;
     return 0;
}