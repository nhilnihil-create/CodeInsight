// https://atcoder.jp/contests/abc084/tasks/abc084_d

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF (1e9)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define LEN(x) (sizeof(x) / sizeof(*(x)))

int dp[100001];
// constexprな素数列挙(エラトステネスの篩)
template <int N> struct calc_prime {
    bool b[N + 1];

    constexpr calc_prime() : b() {
        for (int_fast64_t i = 0; i <= N; ++i)
            b[i] = true;
        b[0] = b[1] = false;
        for (int_fast64_t i = 2; i <= N; ++i) {
            for (int_fast64_t j = i * i; j <= N; j += i)
                b[j] = false;
        }
    }
};
calc_prime<200000> prime;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    REP(i, n) cin >> l[i] >> r[i];
    for (int i = 1; i <= 100000; i++) {
        dp[i] = dp[i - 1] + (prime.b[i] & prime.b[(i + 1) / 2]);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[r[i]] - dp[l[i] - 1] << "\n";
    }

    return 0;
}