#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    double n,t=0;
    cin>>n;
    vector<double> a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
        t+=a[i];
    }
    double p=t/n,m=LLONG_MAX,mi;
    for(ll i=n-1;i>=0;--i){
        double tt=abs(a[i]-p);
        if(tt<=m){
            m=tt;
            mi=i;
        }
    }
    cout<<mi;
}
