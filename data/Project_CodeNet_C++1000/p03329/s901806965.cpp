#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int INF = 1000000;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        int tmp = dp[i-1] + 1;
        rep(j, 10) {
            if (i-pow(6, j)<0) break;
            tmp = min(tmp, dp[i-pow(6, j)] + 1);
        }
        rep(j, 10) {
            if (i-pow(9, j)<0) break;
            tmp = min(tmp, dp[i-pow(9, j)] + 1);
        }
        dp[i] = tmp;
    }
    cout << dp[n] << endl;
}