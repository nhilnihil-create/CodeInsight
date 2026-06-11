#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow2(x) (ll(1)<<x)
#define pb push_back
#define mp make_pair
#define w(t) int t;scanf("%d",&t);while(t--)
#define For(i,n) for(int i=0;i<n;i++)
#define scan(n) int n;scanf("%d", &n);
using namespace std;
const int sz = 3002;
int n,m;
string x,y;
int dp[sz][sz];
int solve(int i,int j,string temp)
{
    if(i==n || j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(x[i]==y[j])
        return dp[i][j] = solve(i+1,j+1,temp + x[i]) + 1;
    return dp[i][j] = max(solve(i+1,j,temp),solve(i,j+1,temp));
}
void build(int i,int j,string temp)
{
    if(i==n || j==m)
        return ;
    if(dp[i][j]==solve(i+1,j+1,temp + x[i]) + 1 && x[i]==y[j])
    {
        cout<<x[i];
        build(i+1,j+1,temp + x[i]);
    }
    else if(dp[i][j]==solve(i+1,j,temp))
        build(i+1,j,temp);
    else
        build(i,j + 1,temp);
}
int main()
{
    cin>>x>>y;
    n = x.size(),m = y.size();
    memset(dp,-1,sizeof dp);
    solve(0,0,"");
    build(0,0,"");
}
