#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll X;
    cin >> n >> X;
    ll x;
    cin >> x;
    ll ans = abs(X - x);
    rep(i,n-1){
        cin >> x;
        ans = gcd(ans, abs(X - x));
    }
    cout << ans << endl;
    return 0;
}
