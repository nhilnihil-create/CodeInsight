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
    map<int, int> dp;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int m = INF;
        if(dp[a[i-1]]>0) m = min(m, dp[a[i-1]]);
        for (int k = 0; k < 26; k++) {
            int ak = a[i-1]^(1 << k);
           if(dp[ak]>0) m = min(m, dp[ak]);
        }
        opt[i] = m;
        if (dp[a[i-1]]>0)dp[a[i-1]] = min(dp[a[i-1]], m+1);
        else dp[a[i-1]] = m+1;
    }
    cout << opt[N] << endl;
    return 0;
}
