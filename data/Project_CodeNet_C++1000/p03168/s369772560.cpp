#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Logging
//#define DEBUG
#if defined(DEBUG)
#define debug(x) print(x)
#define sdebug(x) sprint(x)
#else
#define debug(x) \
    {}
#define sdebug(x) \
    {}
#endif

#define print(x) std::cout << x << "\n";
#define sprint(x) std::cout << x;
#define FOR(i, x, y) for (size_t i = x; i < (y); i++)
#define PB push_back

#define ll int64_t
#define vi vector<int>

using namespace std;
template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vt) {
    if (vt.empty())
        return os;
    for (size_t i = 0; i + 1 < vt.size(); i++) {
        os << vt[i] << " ";
    }
    os << vt.back();
    return os;
}

struct Timer {
    std::chrono::system_clock::time_point start;
    Timer() {
        start = std::chrono::system_clock::now();
    }

    ~Timer() {
        auto now = std::chrono::system_clock::now();
        std::chrono::system_clock::duration duration = now - start;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        std::string str;
        str = str + "Runtime: " + std::to_string(ms.count()) + " ms";
        debug(str);
    }
};

void solve();
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    Timer time;

    while (t--) {
        solve();
    }
}

// To compute x^y under modulo m
ll power(ll x, ll y, ll m) {
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

ll inv_mod(ll x, ll m) {
    ll g = gcd(x, m);
    if (g != 1) {
        cout << "Inverse doesn't exist";
        return g;
    } else {
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(x, m - 2, m);
    }
}

ll mod(ll x, ll y) {
    ll ans = x % y;
    if (ans < 0)
        ans += y;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<double> probs(n);
    for (int i = 0; i < n; i++) {
        cin >> probs[i];
    }
    vector<double> dp(2 * n + 1);
    dp[n + 1] = probs[0];
    dp[n - 1] = 1 - probs[0];
    for (int i = 1; i < n; i++) {
        vector<double> newdp(dp.size() + 2);
        for (int j = -i; j <= i; j++) {
            newdp[n + j + 1] += dp[n + j] * probs[i];
            newdp[n + j - 1] += dp[n + j] - dp[n + j] * probs[i];
        }
        dp = move(newdp);
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[n + i];
    }
    printf("%.10f",ans);
}