#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1e9+7;
const int INF = 1<<30;
const ll LINF = 1LL<<60;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, C;
    cin >> n >> C;
    vector<vector<int>> D(C, vector<int>(C, 0));
    rep(i, C) {
        rep(j, C) cin >> D[i][j];
    }
    vector<vector<int>> fi(n, vector<int>(n, 0));
    rep(i, n) {
        rep(j, n) cin >> fi[i][j], --fi[i][j];
    }

    vector<vector<int>> cost(3, vector<int>(C, 0));
    rep(i, C) {
        rep(j, n) {
            rep(k, n) {
                cost[(j + k) % 3][i] += D[fi[j][k]][i];
            }
        }
    }

    int res = INF;
    int c[3];
    for (c[0] = 0; c[0] < C; ++c[0]) {
        for (c[1] = 0; c[1] < C; ++c[1]) {
            if (c[1] == c[0]) continue;
            for (c[2] = 0; c[2] < C; ++c[2]) {
                if (c[2] == c[0] || c[2] == c[1]) continue;
                int tmp = 0;
                for (int it = 0; it < 3; ++it) tmp += cost[it][c[it]];
                res = min(res, tmp);
            }
        }
    }
    cout << res << endl;
    return 0;
}