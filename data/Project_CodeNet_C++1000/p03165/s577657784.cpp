#include <bits/stdc++.h>

#define int long long

using namespace std;

string s, t;
int dp[10001][10001];
string ans;


void path(int i, int j){
   // cout << i << " " << j << endl;
    if(i == 0 || j == 0){
        return;
    }
    if(dp[i][j] == dp[i - 1][j]){
        path(i - 1, j);
    }
    else if(dp[i][j] == dp[i][j - 1]){
        path(i, j - 1);
    }
    else{
        ans += s[i - 1];
        path(i - 1, j - 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);

    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    path(n, m);
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}