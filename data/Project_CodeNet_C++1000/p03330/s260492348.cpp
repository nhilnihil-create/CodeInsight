#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _repi(i, a, b) for (int i = int(a), i##_hoge = int(b); i < i##_hoge; ++i)
#define _rep(i, n) _repi(i, 0, n)
#define REP(...) _overload3(__VA_ARGS__, _repi, _rep, )(__VA_ARGS__)
#define FOREACH(i, x) for (auto &i : x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define print(x) cout << x << endl;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
template <class T> using vv = vector<vector<T>>;
// clang-format off
template <class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return 1;}return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return 1;}return 0;}
// clang-format on


int main() {
    int N, C;
    cin >> N >> C;

    vvint D(C, vint(C));
    REP(i, C) REP(j, C) { cin >> D[i][j]; }

    // cost[i][to] i(mod3)類をすべてtoにするときの違和感の合計
    vvint cost(3, vint(C));

    int c;
    REP(i, N) REP(j, N) {
        cin >> c;
        c--;
        REP(to, C) cost[(i + 1 + j + 1) % 3][to] += D[c][to];
    }

    int ans = INF;
    REP(i, C) REP(j, C) REP(k, C) {
        if (i == j || j == k || k == i) continue;
        chmin(ans, cost[0][i] + cost[1][j] + cost[2][k]);
    }
    print(ans);
}