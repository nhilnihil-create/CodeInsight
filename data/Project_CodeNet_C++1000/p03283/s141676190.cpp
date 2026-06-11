#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++)
    {
        int L, R; cin >> L >> R;
        L--; R--;
        dp[L][R]++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(j > 0) dp[i][j] += dp[i][j-1];
        }

    }


    vector<int> ans(Q, 0);
    for (int i = 0; i < Q; i++)
    {
        int p, q; cin >> p >> q;
        p--; q--;
        for (int j = p; j <= q; j++)
        {
            if(p > 0)ans[i] += dp[j][q] - dp[j][p-1];
            else ans[i] += dp[j][q];
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}