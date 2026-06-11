
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, MAX = 2e5 + 2;
int sumDp[MAX];
int main() {
    //ifstream cin("gard6.in");
    int n;
    cin >> n;
    vector<int>c;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(c.empty() || c.back() != x)
            c.push_back(x);
    }

    n = c.size();
    vector<int>dp(n);
    dp[0] = 1;
    sumDp[c[0]] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = (dp[i - 1] + sumDp[c[i]]) % MOD;
        sumDp[c[i]] = (sumDp[c[i]] + dp[i - 1]) % MOD;
    }
    cout << dp[n - 1];
}
