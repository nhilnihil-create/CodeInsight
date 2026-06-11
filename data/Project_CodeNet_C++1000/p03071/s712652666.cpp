#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0,z=0,x=0;
    cin>>a>>b;
    c=a+b;
    d=max(a,b);
    d=(d*2)-1;
    cout<<max(c,d);
    return 0;
}
