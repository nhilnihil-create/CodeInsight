#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n,h; cin>>n>>h;
    vector<ll> a(n), b(n);
    rep(i,n) cin>>a[i]>>b[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    ll res=0;
    rep(i,n){
        if(b[i]<a[0] || h<=0) break;
        h-=b[i];
        res++;
    }
    if(h>0){
        if(h%a[0]==0) res+=h/a[0];
        else res+=h/a[0] + 1;
    }
    cout<<res<<endl;
    return 0;
}