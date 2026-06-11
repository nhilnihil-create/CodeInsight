#include <bits/stdc++.h>
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
#define rep(i, m, n) for (int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for (int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef vector<vector<vector<ll>>> mat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// vector<long long> v(n), c(n);
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(k+1, 0)));

// ll dp[1005][3] = {99999999};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    ll H, W;
    cin >> H >> W;
    vector<string> s(H);
    rep(i, 0, H) cin >> s[i];
    vector<vector<ll>> dp(H+2, vector<ll>(W+2,0));
    dp[1][1] = 1;
    rep(i, 1, H+1) {
        rep(j, 1, W+1) {
            if (s[i-1][j-1] == '#') {
                continue;
            }
            if (i > 1) dp[i][j] += dp[i-1][j];
            if (j > 1) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[H][W] << '\n';
    return 0;
}
