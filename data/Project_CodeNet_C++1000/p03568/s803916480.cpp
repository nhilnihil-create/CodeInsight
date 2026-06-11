#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll res=1, odd=1;
    rep(i,n){
        res*=3;
        if(a[i]%2==0) odd*=2;
    }
    cout<<res-odd<<endl;
    return 0;
}