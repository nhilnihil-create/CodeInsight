#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int inf = -1e9;
    for(int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> cost(m);
    for(int i = 0; i < m; i++){
        if(a[i] == 1) cost[i] = 2;
        else if(a[i] == 2 || a[i] == 3 || a[i] == 5) cost[i] = 5;
        else if(a[i] == 4) cost[i] = 4;
        else if(a[i] == 6 || a[i] == 9) cost[i] = 6;
        else if(a[i] == 7) cost[i] = 3;
        else cost[i] = 7;
    }
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(i - cost[j] >= 0)
                dp[i] = max(dp[i], dp[i - cost[j]] + 1);
        }
    }
    int l = dp[n];
    vector<int> ans(l);
    int i = 0;
    while(n > 0){
        for(int j = m - 1; j >= 0; j--){
            if(n - cost[j] >= 0 && dp[n] == dp[n - cost[j]] + 1){
                ans[i] = a[j];
                i++;
                n -= cost[j];
                break;
            }
        }
    }
    for(int i = 0; i < l; i++)
        cout << ans[i];
    cout << endl;
    return 0;
}