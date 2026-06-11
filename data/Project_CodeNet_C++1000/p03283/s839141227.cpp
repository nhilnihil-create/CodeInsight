#include <bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;

int main()
{
    ll n,m,q; cin >> n >> m >> q;
    vector<vector<ll>>G(n+1,vector<ll>(n+1,0));
    for(int i = 0; i < m; i++)
    {
        ll l,r; cin >> l >> r;
        G[l][r] += 1;
    }
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + G[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {
        int p,q; cin >> p >> q;
        cout << dp[q][q] - dp[q][p-1] - dp[p-1][q] + dp[p-1][p-1] << endl;
    }
}