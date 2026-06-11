#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n; cin>>n;
    vector<ll> v(n), c(n);
    rep(i, n) cin>>v[i];
    rep(i, n) cin>>c[i];
    ll res=0;
    rep(i, n) res += max(0ll, v[i] - c[i]);
    cout<<res<<endl;
    return 0;
}