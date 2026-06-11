#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n){
        a[i]-=(i+1);
    }
    sort(a.begin(),a.end());
    ll all=(n%2==0)? (a[n/2-1]+a[n/2])/2:a[n/2];
    ll res=1e+18+3;
    for(ll i=-10;i<=10;i++){
        ll nn=all+i;
        ll buf=0;
        rep(j,n){
            buf+=abs(a[j]-nn);
        }
        chmin(res,buf);
    }
    cout<<res<<endl;
}
