#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i]) continue;
            else return a[i] < b[i];
        }
    } else {
        return a.length() < b.length();
    }
    return true;
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> match = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<vector<string>> dp(20, vector<string>(N + 5, ""));
    vector<int> use(M);
    for (int i = 0; i < M; i++) cin >> use[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (match[use[k]] > i) continue;
                // cout << i << " " << j << " " << k << endl;
                if (dp[use[k]][i - match[use[k]]] != "" || i - match[use[k]] == 0) dp[use[j]][i] = max(dp[use[j]][i], dp[use[k]][i - match[use[k]]] + to_string(use[k]), compare);
            }
        }
    }
    string ans = "";
    for (int i = 1; i <= 10; i++) ans = max(ans, dp[i][N], compare);
    cout << ans << endl;
}

