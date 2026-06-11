#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m, 0), lag(m-1);
    rep1(i, m) cin >> a[i];
    if (m <= n){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    rep1(i, m){
        lag[i] = abs(a[i+1] - a[i]);
    }
    sort(lag.begin(), lag.end());
    ll ans = 0;
    rep1(i, m-n) ans += lag[i];
    cout << ans << endl;
    //printf("%.12f", ans);
}