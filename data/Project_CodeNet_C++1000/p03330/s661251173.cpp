#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1000000000
using namespace std;
using ll = long long;
int dp[3][32];
int main()
{
    int n,c;
    cin >> n >> c;
    vector<vector<int>> d(c,vector<int>(c)), col(n,vector<int>(n));
    rep(i,c){
        rep(j,c){
            cin >> d[i][j];
        }
    }
    rep(i,n){
        rep(j,n){
            cin >> col[i][j];
            col[i][j]--;
        }
    }
    rep(i,n){
        rep(j,n){
            rep(k,c){
                dp[(i + j) % 3][k] += d[col[i][j]][k];
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < c;k++){
                if(k == j || k == i)
                    continue;
                ans = min(ans,dp[0][i] + dp[1][j] + dp[2][k]);
            }
        }
    }
    cout << ans << endl;
}
