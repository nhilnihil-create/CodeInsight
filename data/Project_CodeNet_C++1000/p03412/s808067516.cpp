#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll a[200000], b[200000], d[200000], c=0, e=1;
int f(ll x){
    if(d[0]>=x)return 0;
    if(d[n-1]<x)return n;
    int l=0, r=n-1;
    while(l+1<r){
        int m=(l+r)/2;
        if(d[m]<x){
            l=m;
        }else{
            r=m;
        }
    }
    return l+1;
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<30;i++){
        for(int j=0;j<n;j++){
            d[j]=b[j]%(e*2);
        }
        sort(d, d+n);
        ll t=0;
        for(int j=0;j<n;j++){
            ll x=a[j]%(e*2);
            t+=f(e*4-x)-f(e*3-x)+f(e*2-x)-f(e-x);
        }
        t%=2;
        c+=(t<<i);
        e*=2;
    }
    cout<<c<<endl;

}
