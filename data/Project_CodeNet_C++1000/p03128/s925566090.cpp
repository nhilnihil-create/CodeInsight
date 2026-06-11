#include<bits/stdc++.h>
using namespace std;

#define LL long long
int n, m, x;
int c[] = {1000000000, 2, 5, 5, 4, 5, 6, 3, 7, 6}, d[10];
string ans = "";

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> d[i];

    sort(d, d + m);
    reverse(d, d + m);

    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= n; j++) {
            int x = c[d[i]];
            if(j + x <= n) dp[j + x] = max(dp[j + x], dp[j] + 1);
        }
    }

    int mx = dp[n];
    for(int i = 0; i < mx; i++) {
        for(int j = 0; j < m; j++) {
            int x = c[d[j]];
            if(n - x >= 0 && dp[n-x] == dp[n] - 1) {
                ans += d[j] + '0';
                n -= x;
                break;
            }
        }
    }

    cout << ans;
}