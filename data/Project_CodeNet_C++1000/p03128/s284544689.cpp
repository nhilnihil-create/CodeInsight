#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 200000000;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> num = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int N, M;
    cin >> N >> M;
    auto A = make_vec<int>(M);
    REP(i, M) { cin >> A.at(i); }
    sort(ALL(A), greater<int>());

    vector<int> dp(N + 4, -INF);
    dp[0] = 0;
    REP(i, N + 1) {
        REP(j, M) {
            if (i >= num[A[j]]) {
                dp[i] = max(dp[i], dp[i - num[A[j]]] + 1);
            }
        };
    }

    int cur = N;
    string S = "";
    while (cur > 0) {
        for (auto a : A) {
            // cout << "cur:" << cur << " a:" << a << endl;
            if (cur - num[a] >= 0) {
                if (dp[cur - num[a]] == dp[cur] - 1) {
                    cur = cur - num[a];
                    S.push_back(a + '0');
                    break;
                }
            }
        }
    }
    cout << S << endl;

    return 0;
}
