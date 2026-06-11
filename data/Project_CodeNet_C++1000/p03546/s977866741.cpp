#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int c[10][10];

int main() {
    int h, w;
    cin >> h >> w;
    rep (i, 10) rep (j, 10) cin >> c[i][j];
    int a[h][w];
    int ans = 0;
    rep (k, 10) {
        rep (i, 10) {
            rep (j, 10) {
                c[i][j] = min (c[i][k] + c[k][j], c[i][j]);
            }
        }
    }
    rep (i, h) {
        rep (j, w) {
            cin >> a[i][j];
            if (a[i][j] == -1) continue;
            ans += c[a[i][j]][1];
        }
    }
    cout << ans << "\n";
}