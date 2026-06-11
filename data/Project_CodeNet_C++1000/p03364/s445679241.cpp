#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int N, M, K, Q, W, H, R, C;
char S[400][400];
int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        REP(j, N) { cin >> S[i][j]; }
    }

    int ans = 0;
    REP(A, N) {
        bool flag = true;
        // cout << A << endl;
        REP(h, N) {
            REP(w, N) {
                // cout << h << " " << w << " " << S[h][w] << " : ";
                // cout << (N + w - A) % N << " " << (h + A) % N << " " << S[(N + w - A) % N][(h + A) % N] << endl;
                if (S[h][w] != S[(N + w - A) % N][(h + A) % N]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) ans += N;
    }

    cout << ans << endl;
    return 0;
}
