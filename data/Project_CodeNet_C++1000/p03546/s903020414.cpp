#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int h, w;
    cin >> h >> w;
    mat c(10, vec(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    mat a(h, vec(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    rep(k, 10) rep(i, 10) rep(j, 10) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }

    int res = 0;

    rep(i, h) rep(j, w) {
        if (a[i][j] == -1) continue;
        res += c[a[i][j]][1];
    }

    cout << res << endl;
    return 0;
}