#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <list>
#include <cmath>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define REP(i, n) for (int64_t i = 0; i < (int64_t)n; i++)
#define REP_FOR(i, a, b) for (int64_t i = (int64_t)a; i < (int64_t)b; i++)
#define REP_REV(i, a, b) for (int64_t i = (int64_t)a; i > (int64_t)b; i--)
#define FORALL(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int64_t, int64_t> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int64_t> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int64_t infi = 1147483600;
const ll infl = 4e18 + 5;
const char EOL = '\n';
//cout << fixed << setprecision(17) << res << endl;
// const ll MOD = 1000000009;


int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> A(m);
    for (auto & a: A) cin >> a;

    ll matches[10] = {0,2,5,5,4,5,6,3,7,6};

    vector<pair<string,ll>> keys;
    for (auto a : A) {
        keys.push_back(make_pair(a, matches[a[0]-'0']));
    }

    vector<string> dp(n + 1, "NA");
    dp[0] = "";

    for (ll i = 1; i <= n; ++i) {
        for (auto k : keys) {
            ll j = i - k.second;
            if (j >= 0 && dp[j] != "NA") {
                if (dp[i] == "NA") {
                    dp[i] = dp[j] + k.first;
                } else {
                    if (dp[i].length() < dp[j].length() + 1) {
                        dp[i] = dp[j] + k.first;
                    } else if (dp[i].length() == (dp[j].length() + 1)) {
                        auto tmp = dp[j] + k.first;
                        if (dp[i].compare(tmp) < 0) {
                            dp [i] = tmp;
                        }
                        tmp = k.first + dp[j];
                        if (dp[i].compare(tmp) < 0) {
                            dp [i] = tmp;
                        }
                    }
                }
            }
        }
    }
    //for (auto p : dp) {
    //    cerr << p << endl;
    //}

    cout << dp[n] << endl;
}
