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
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) for (int i = 1; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int N;
lint C;
vector<lint> x, v;

lint solve() {
    vector<lint> S(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + v[i];
    rep(i, N) S[i + 1] -= x[i];
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    vector<lint> T(N + 1, 0);
    rep(i, N) T[i + 1] = T[i] + v[i];
    rep(i, N) T[i + 1] -= (C - x[i]);
    rep(i, N) T[i + 1] = max(T[i], T[i + 1]);
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    lint res = 0;
    REP(i, N + 1) {
        res = max(res, S[i]);
        res = max(res, S[i] - x[i - 1] + T[N - i]);
    }
    return res;
}

int main() {
    cin >> N >> C;
    x = v = vector<lint>(N);
    rep(i, N) cin >> x[i] >> v[i];
    
    lint ans = solve();
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    rep(i, N) x[i] = C - x[i];
    ans = max(ans, solve());
    cout << ans << "\n";
    return 0;
}
