#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
vector<vector<char>> v(1003,vector<char>(1003));
vector<vector<int>> dp(1003,vector<int>(1003,-1));
int n,m;
ll solve(int i,int j)
{
    if(i>n||j>m||v[i][j]=='#')
    return 0;
    if(i==n&&j==m)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    ll ans =  (solve(i+1,j)%mod + solve(i,j+1)%mod)%mod;
    return dp[i][j] = (int)ans;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v[i][j];
        }
    }
    cout<<solve(1,1)%mod;
}
