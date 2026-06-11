#include <iostream>
#include <math.h>
using namespace std;
int main(void){
    int d,n;
    cin>>d>>n;
    int p = 1;
    if (d){
    for (int i=0;i<d;i++){
        p*=100;
    }}
    if (n!=100){
        cout<<n*p<<endl;
    }
    else{
        cout<<(n+1)*p<<endl;
    }
}
