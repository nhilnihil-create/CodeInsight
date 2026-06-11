#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

int dp[3030][3030];
void solve(long long N, std::string s) {
    memset(dp, 0, 3030 * 3030 * sizeof(dp[0][0]));

    rep(i, N) dp[0][i] = 1;
    rep(i, s.size()) {
        vi cum(N + 1);
        rep(j, N) {
            cum[j + 1] = dp[i][j] + cum[j];
            cum[j + 1] %= mod;
        }
        if (s[i] == '<') {
            rep(j, N - i) {
                // for (int k = j + 1; k < N - i; k++) {
                //     dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % mod;
                // }
                dp[i + 1][j] = (dp[i + 1][j] + cum[N - i] - cum[j + 1] + mod) % mod;
            }
        } else {
            rep(j, N - i) {
                // for (int k = 0; k < j + 1; k++) {
                //     dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % mod;
                // }
                dp[i + 1][j] = (dp[i + 1][j] + cum[j + 1] - cum[0] + mod) % mod;
            }
        }
    }

    cout << dp[s.size()][0] << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    long long N;
    cin >> N;
    std::string s;
    std::cin >> s;
    solve(N, s);
    return 0;
}
