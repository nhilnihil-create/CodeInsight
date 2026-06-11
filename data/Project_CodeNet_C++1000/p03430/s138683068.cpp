#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n    = s.size();
    string t = s;
    reverse(t.begin(), t.end());
    vector<vvi> dp(n + 5, vvi(n + 5, vi(k + 5, 0)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= k; ++l) {
                chmax(dp[i + 1][j][l], dp[i][j][l]);
                chmax(dp[i][j + 1][l], dp[i][j][l]);
                if (s[i] == t[j]) {
                    chmax(dp[i + 1][j + 1][l], dp[i][j][l] + 1);
                } else {
                    chmax(dp[i + 1][j + 1][l + 1], dp[i][j][l] + 1);
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= n; ++i) {
        chmax(ret, dp[i][n - i][k] * 2);
    }
    for (int i = 0; i < n; ++i) {
        chmax(ret, dp[i][n - 1 - i][k] * 2 + 1);
    }
    cout << ret << "\n";
    return 0;
}