#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000007;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, K; cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    vector<ll> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= K; ++j) {
            if (i+j < N) chmin(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}