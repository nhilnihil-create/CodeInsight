#include<iostream>
using namespace std;
int main(){
    int a,b,x,y,z,maxim;
    cin>>a>>b;
    x=a+b;
    y=a*b;
    z=a-b;
    maxim=max(x,y);
    maxim=max(maxim,z);
    cout<<maxim;
}
