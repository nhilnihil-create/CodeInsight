#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define INF 1000000000000
#define MOD 1000000007
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cout << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3)                                                 \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << endl
#define debug_4(x1, x2, x3, x4)                                             \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5)                                         \
    cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
         << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#ifdef _DEBUG
#define debug(...)                                                        \
    CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
    (__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using ll = long long;

template <class T>
void printVector(const vector<T>& v) {
    for (auto value : v) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int d;
    ll g, ans = INF;  // scoreがg点以上
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    rep(i, 1 << d) {
        vector<int> used_bits;
        debug(" ");
        debug(i);
        ll score = 0, cnt = 0;
        rep(j, d) {
            if (i >> j & 1) {
                score += 100 * (j + 1) * p[j] + c[j];
                cnt += p[j];
                if (cnt == p[j]) {
                    debug(cnt, p[j]);
                    used_bits.push_back(j);
                }
            }
        }
        debug(i, score, abs(score - g), cnt);
        if (score < g) {
            debug("足し算");
            rrep(j, d) {
                if (find(used_bits.begin(), used_bits.end(), j) !=
                    used_bits.end()) {
                    debug(p[j], "continue");
                    continue;
                }
                rep(k, p[j]) {
                    score += 100 * (j + 1);
                    cnt++;
                    debug(j, score, 100 * (j + 1), p[j], cnt);
                    debug(g, k);
                    if (score >= g) {
                        debug(cnt, "break");
                        break;
                    };
                }
                if (score >= g) {
                    ans = min(ans, cnt);
                    break;
                };
            }
        } else {
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
