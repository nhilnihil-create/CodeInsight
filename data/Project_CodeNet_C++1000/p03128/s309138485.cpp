#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline T GCD(T a, T b) {
    return b ? GCD(b, a % b) : a;
}
template<class T>
inline T LCM(T a, T b) {
    return (a + (b - 1)) / b;
}

int round_int(int a, int b) {
    return (a + (b - 1)) / b;
}

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

constexpr array<int, 9> cost = { 2,5,5,4,5,6,3,7,6 };
const string MINUS_INF = "-";

string dp[11000];

void chmax(string& a, string b) {
    if (a == MINUS_INF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vi a(m);
    rep(i, m) cin >> a[i];

    rep(i, 11000) dp[i] = MINUS_INF;
    dp[0] = "";

    for(int i = 0; i <= n; ++i) {
        if (dp[i] == MINUS_INF) continue;
        rep(j, m) {
            chmax(dp[i + cost[a[j] - 1]], dp[i] + char('0' + a[j]));
        }
    }
    cout << dp[n] << endl;
}