#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1000000009
using namespace std;
using ll = long long;
int main()
{
    int n, nc;
    cin >> n >> nc;
    vector<int> s(n), t(n), c(n);
    rep(i,n){
        cin >> s[i] >> t[i] >> c[i];
        c[i]--;
    }
    vector<vector<int>> dp(nc, vector<int>(200002));
    rep(i,n){
        for (int j = s[i]*2-1; j <= t[i]*2;j++){
            dp[c[i]][j] = 1;
        }   
    }
    int ans = 0;
    rep(i,200002){
        int cnt = 0;
        rep(j,nc){
            if(dp[j][i])
                cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}