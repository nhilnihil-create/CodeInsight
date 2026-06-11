#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

struct Block {
    ll w, s, v;
    bool operator<(const Block &rhs) const {
        return s + w < rhs.s + rhs.w;
    }
};

void solve() {
    int N;
    cin >> N;
    vector<Block> B(N);
    for (int i = 0; i < N; i++) {
        ll w, s, v;
        cin >> w >> s >> v;
        B[i] = {w, s, v};
    }
    sort(all(B));

    const ll inf = 2e18;
    vector<vector<ll>> dp(N + 1, vector<ll>(20001, -inf));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= 20000; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j <= B[i].s && j + B[i].w <= 20000) {
                dp[i + 1][j + B[i].w] = max(dp[i + 1][j + B[i].w], dp[i][j] + B[i].v);
            }
        }
    }

    ll ans = 0;
    for(int j = 0; j <= 20000; j++) {
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}