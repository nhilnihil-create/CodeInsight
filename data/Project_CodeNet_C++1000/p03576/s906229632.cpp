#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    
    vector<pair<int, int>> S1(N);
    rep(i, N) S1[i] = pair<int, int>{x[i], i};
    sort(ALL(S1));
    vector<int> X(N, 0);
    X[S1[0].second] = 0;
    REP(i, N) X[S1[i].second] = X[S1[i - 1].second] + 1;
    vector<pair<int, int>> S2(N);
    rep(i, N) S2[i] = pair<int, int>{y[i], i};
    sort(ALL(S2));
    vector<int> Y(N, 0);
    Y[S2[0].second] = 0;
    REP(i, N) Y[S2[i].second] = Y[S2[i - 1].second] + 1;
    
    vector<vector<int>> S(N, vector<int>(N, 0));
    rep(i, N) S[X[i]][Y[i]] = 1;
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));
    rep(i, N) rep(j, N) sum[i + 1][j + 1] = S[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    ll ans = INF;
    rep(i, N + 1) rep(j, N + 1) rep(k, N + 1) rep(l, N + 1) {
        if (i < j && k < l) {
            if (sum[j][l] - sum[i][l] - sum[j][k] + sum[i][k] >= K) {
                ans = min(ans, ((ll)S1[j - 1].first - (ll)S1[i].first) * ((ll)S2[l - 1].first - (ll)S2[k].first));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
