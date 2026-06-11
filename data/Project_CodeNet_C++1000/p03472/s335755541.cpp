#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(),greater<ll>());
    ll a_max = a.back();
    ll cnt = 0;
    rep(i,n) {
        if(b[i] <= a_max) break;
        if(h <= 0) break;
        cnt++;
        h -= b[i];
    }
    if (h>0) cnt += (h+a_max-1)/a_max;
    /*
    while(h>0) {
        cnt++;
        h-=a_max;
    }*/
    cout << cnt << endl;
}