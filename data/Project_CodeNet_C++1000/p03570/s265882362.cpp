#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int INF = 9999999;
    string s;
    cin >> s;
    int N = s.size();
    vector<int> a(N, 0);
    for (int i = 0; i < N; i++) {
        int d = (1 << (int)(s[i]-'a'));
        if (i == 0) a[0] = d;
        else a[i] = a[i-1]^d;
    }
    vector<int> opt(N+1, INF);
    opt[0] = 0;
    vector<int> dp(1 << 26, INF);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        int m = INF;
        m = min(m, dp[a[i-1]]);
        for (int k = 0; k < 26; k++) {
            m = min(m, dp[a[i-1]^(1 << k)]);
        }
        opt[i] = m+1;
        dp[a[i-1]] = min(dp[a[i-1]], m+1);
    }
    cout << opt[N] << endl;
    return 0;
}
