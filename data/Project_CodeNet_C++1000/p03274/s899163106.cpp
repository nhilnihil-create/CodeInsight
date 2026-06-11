#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e9 + 7;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep1(i, n) cin >> a[i];
    ll ans = INF;
    for (ll i=0; i+k-1<(n); i++){
        ll res;
        if (a[i+k-1]*a[i]>=0) res = max(abs(a[i+k-1]), abs(a[i]));
        else res = max(abs(a[i+k-1]), abs(a[i])) + min(abs(a[i+k-1]), abs(a[i]))*2;
        ans = min(ans, res);
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}