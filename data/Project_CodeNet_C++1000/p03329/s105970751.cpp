#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;

    vector<int> money;
    money.push_back(1);
    int p = 6;
    for(int i=0; p<=n; i++){
        money.push_back(p);
        p *= 6;
    }
    p = 9;
    for(int i=0; p<=n; i++){
        money.push_back(p);
        p *= 9;
    }
    sort(money.begin(), money.end());

    int INF = (1LL<<40);
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for(int i=0; i<money.size(); i++){
        for(int j=0; j+money[i]<=n; j++){
            dp[j+money[i]] = min(dp[j] + 1, dp[j+money[i]]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}