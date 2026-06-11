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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    vector<ll> sum(N + 1, 0);
    rep(i, N) sum[i + 1] = sum[i] + A[i];
    
    ll ans = INF;
    for (int y = 2; y <= N - 2; ++y) {
        vector<int> x(2, 0), z(2, 0);
        x[1] = (int)(upper_bound(ALL(sum), sum[y] / 2) - sum.begin());
        if (x[1] == 1) x[0] = x[1];
        else x[0] = x[1] - 1;
        z[1] = (int)(upper_bound(ALL(sum), sum[y] + (sum[N] - sum[y]) / 2) - sum.begin());
        if (z[1] == y + 1) z[0] = z[1];
        else z[0] = z[1] - 1;
        rep(i, 2) rep(j, 2) {
            ll MAX = max({sum[x[i]] - sum[0], sum[y] - sum[x[i]], sum[z[j]] - sum[y], sum[N] - sum[z[j]]});
            ll MIN = min({sum[x[i]] - sum[0], sum[y] - sum[x[i]], sum[z[j]] - sum[y], sum[N] - sum[z[j]]});
            ans = min(ans, MAX - MIN);
        }
    }
    cout << ans << "\n";
    return 0;
}
