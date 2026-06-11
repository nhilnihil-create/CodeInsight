#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
constexpr double EPS = 1e-10;
constexpr int INF = 1001001001;
//constexpr ll INF = 1001001001001001001ll;


vi hashc[200005];

int main() {
    int N; cin >> N;
    rep(i, N) {
        int c; cin >> c;
        hashc[c].pb(i);
    }

    vi next(N, -1);

    rep(c, 200005) {
        int n = hashc[c].size();
        if (n <= 1) continue;
        for (int i = n - 1 ; i >= 0; i--) {
            if (i == n - 1) continue;
            if (hashc[c][i + 1] > hashc[c][i] + 1) {
                next[hashc[c][i]] = hashc[c][i + 1];
            }
        }
    }

    vll dp(N, 0);
    dp[N - 1] = 1;
    for (int i = N - 2 ; i >= 0 ; i--) {
        dp[i] = dp[i + 1];
        if (next[i] != -1) dp[i] += dp[next[i]];
        dp[i] %= MOD;

    }

    cout << dp[0] << endl;

}