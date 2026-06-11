#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int h, w;
int c[11][11];
int a[205][205];

int main() {
    cin >> h >> w;
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(k, 10) rep(i, 10) rep(j, 10) {
        chmin(c[i][j], c[i][k] + c[k][j]);
    }

    int ans = 0;
    rep(i, h) rep(j, w) {
        if (a[i][j] < 0) continue;
        ans += c[a[i][j]][1];
    }
    cout << ans << endl;
}
