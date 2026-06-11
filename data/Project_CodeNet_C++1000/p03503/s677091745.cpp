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
    ll n;
    cin >> n;
    vector<vector<ll> > f(n, vector<ll>(10)), p(n, vector<ll>(11));
    rep1(i, n) rep1(j, 10) cin >> f[i][j];
    rep1(i, n) rep1(j, 11) cin >> p[i][j];
    ll ans;
    for (ll bit=1; bit<(1<<10); bit++){
        vector<ll> c(n);
        for (ll i = 0; i < 10; ++i) {
            if (bit & (1 << i)) {
                for (ll j = 0; j < n; ++j) c[j] += f[j][i];
            }
        }
        ll sum = 0;
        for (ll i = 0; i < n; ++i) sum += p[i][c[i]];
        if (bit==1) ans = sum;
        else ans = max(ans, sum);
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}