#include <bits/stdc++.h>
using namespace std;

int main(){
    long n;cin>>n;
    vector<long> a(n);
    vector<long> b(n);
    vector<long> c(n);
    for(long i=0;i<n;i++)cin>>a[i];
    for(long i=0;i<n;i++)cin>>b[i];
    for(long i=0;i<n;i++)cin>>c[i];
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    long res=0;
    for(long i=0;i<n;i++){
        auto aiter=lower_bound(a.begin(),a.end(),b[i]);
        auto citer=upper_bound(c.begin(),c.end(),b[i]);
        res += (aiter-a.begin())*(c.end()-citer);
    }
    cout<<res<<endl;
}