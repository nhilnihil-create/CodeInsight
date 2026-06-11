#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>a(n),l(n),r(n);
    rep(i,n)cin>>a[i];
    l[0]=a[0];
    r[n-1]=a[n-1];
    for(int i=1; i<n; ++i){
        l[i]=__gcd(l[i-1],a[i]);
    }
    for(int i=n-2; i>=0; --i){
        r[i]=__gcd(r[i+1],a[i]);
    }
    int ans=max(l[n-2],r[1]);
    for(int i=1; i<n-1; ++i){
        ans=max(ans,__gcd(l[i-1],r[i+1]));
    }
    cout<<ans<<endl;
}