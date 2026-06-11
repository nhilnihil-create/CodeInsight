#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0,z=0;
    cin>>a>>b>>c;
    c+=0.5;
    z=c;
    while(z>a){
        d++;
        z-=a;
    }
    cout<<d*b;
    return 0;
}
