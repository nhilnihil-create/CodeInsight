#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll k; cin>>k;
    vector<ll> a(k);
    rep(i,k) cin>>a[i];
    ll nin=2, nax=2;
    for(ll i=k-1; i>=0; i--){
        if(a[i] > nax){
            cout << -1 << endl;
            return 0;
        }
        if(nin%a[i]!=0) nin = a[i] * (1 + nin/a[i]);
        nax = a[i]*(nax/a[i]) + a[i] - 1;

    }
    if(nin > nax) cout << -1 << endl;
    else cout << nin << ' ' << nax << endl;
    return 0;
}