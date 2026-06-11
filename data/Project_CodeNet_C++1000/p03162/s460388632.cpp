#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    while(t--)
    {
    	int n;
    	cin >> n;
    	int value[n][3];
    	for(int i = 0; i < n; i++)
    	    cin >> value[i][0] >> value[i][1] >> value[i][2];
    	int dp[n+1][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + value[i-1][0];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + value[i-1][1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + value[i-1][2];
        }
        cout << max({dp[n][0], dp[n][1], dp[n][2]});
    }
	return 0;
}