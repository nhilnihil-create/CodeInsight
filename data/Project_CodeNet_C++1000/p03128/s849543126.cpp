#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
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

    vector<int> dp(n+1, -INF);
    dp[0]=0;
    for (int i=1; i<10; i++) {
        if ( !d[i] ) continue;
        for (int j=cost[i]; j<=n; j++) {
            int k = j-cost[i];
            if ( dp[k]==-INF ) continue;
            dp[j]=max(dp[j],dp[k]+1);
        }
    }
    int matches=n;
    string ans="";
    while ( matches>0 ) {
        for (int i=9; i>0; i--) {
            if ( !d[i] ) continue;
            if ( matches>=cost[i] && dp[matches]==dp[matches-cost[i]]+1 ) {
                ans+=(char)(i+'0');
                matches-=cost[i];
                break;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}