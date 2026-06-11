#include <bits/stdc++.h>
using namespace std;

int cost[] = {0,2,5,5,4,5,6,3,7,6};
bool d[10] = {};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        d[a] = 1;
    }

    vector<string> dp(n+1, "");
    for (int i=1; i<10; i++) {
        if ( !d[i] ) continue;
        for (int j=cost[i]; j<=n; j++) {
            if ( j-cost[i]>0 && dp[j-cost[i]]=="" ) continue;
            string s=dp[j-cost[i]]+to_string(i);
            sort(s.rbegin(), s.rend());
            if ( s.length()==dp[j].length() ) {
                dp[j]=max(s, dp[j]);
            } else if ( s.length()>dp[j].length() ) {
                dp[j]=s;
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}