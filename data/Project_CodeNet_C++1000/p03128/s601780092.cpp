# include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    const int INF = 1e8;
    int def[10] = {-INF, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int dp[N+1];
    fill(dp, dp + N + 1, -INF);
    vector<pair<int, int>> hand;
    int A[M];
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        if (dp[i] < 0) continue;
        for (int k = 0; k < M; k++) {
            if (def[A[k]] + i > N) continue;
            dp[def[A[k]] + i] = max(dp[i] + 1, dp[def[A[k]] + i]);
        }
    }
    sort(A, A + M, greater<>());
    vector<int> ans;
    int initial = N;
    while (ans.size() < dp[initial]) {
        for (int i = 0; i < M; i++) {
            if (dp[N - def[A[i]]] == dp[N] - 1 && N - def[A[i]] >= 0) {
                N -= def[A[i]];
                ans.push_back(A[i]);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<>());
    for (auto &an : ans) cout << an;
    return 0;
}
