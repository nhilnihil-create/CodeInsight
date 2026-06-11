#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(void){
    long long n,z,o,j,k;
    long long x,y;
    scanf("%lld",&n);
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        o=2*a[i];
        a[i]=o;
    }
    x=0;
    for(int i=0;i<n;i++){
        if(x<a[i]){x=a[i];}
    }
    y=1000000000000;
    for(int i=0;i<n;i++){
        if(a[i]-x/2<y&&-y<a[i]-x/2){
            if(a[i]-x/2<0){y=x/2-a[i];z=0;}else{
                y=a[i]-x/2;z=1;
            }
        }
    }
    o=x/2;
    j=(x/2-y)/2;
    k=(x/2+y)/2;
    if(j==o){j=0;}
    if(k==o){k=0;}
    if(z==0){printf("%lld %lld\n",o,j);}
    if(z==1){printf("%lld %lld\n",o,k);}
}
