#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N, C, D[30][30], c[500][500];
int t[3][30];

int main() {
    cin >> N >> C;
    rep(i, C) rep(j, C) cin >> D[i][j];
    rep(i, N) rep(j, N) cin >> c[i][j];
    rep(i, N) rep(j, N) c[i][j]--;

    rep(i, N) rep(j, N) t[(i+j)%3][c[i][j]]++;
    int ans = INF;
    rep(i, C) rep(j, C) rep(k, C) {
        if (i == j || j == k || k == i) continue;
        int sum = 0;
        rep(l, C) {
            sum += D[l][i] * t[0][l];
            sum += D[l][j] * t[1][l];
            sum += D[l][k] * t[2][l];
        }
        chmin(ans, sum);
    }
    cout << ans << endl;
}
