#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0;
    cin>>a>>b>>c;
    while(b>=a){
        b=b-a;
        d++;
    }
    if(d>=c){cout<<c;}
    if(d<c){cout<<d;}
    return 0;
}
