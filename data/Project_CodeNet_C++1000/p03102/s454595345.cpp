#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> b(m, 0);
    ll a[n][m];
    rep1(i, m) cin >> b[i];
    rep1(i, n){
        rep1(j, m) cin >> a[i][j];
    }
    ll ans = 0, cnt;
    rep1(i, n){
        cnt = c;
        rep1(j, m){
            cnt += b[j]*a[i][j];
        }
        if (cnt>0) ans++;
    }
    cout << ans << endl;
}