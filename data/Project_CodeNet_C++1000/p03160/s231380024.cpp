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
    int N; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];
    vector<ll> dp(N+1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if (i+2 < N) chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[N-1] << endl;
    return 0;
}