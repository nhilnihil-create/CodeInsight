#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    cin>>a>>b;
    if(a>=13){cout<<b;}
    if(a<13){
        if(a>5){cout<<b/2;}
        if(a<=5){cout<<'0';}
    }
    return 0;
}
