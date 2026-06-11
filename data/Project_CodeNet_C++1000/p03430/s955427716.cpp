#include<bits/stdc++.h>
using namespace std;
const int N=305;
string s;
int dp[305][305][305],K;
int dfs(int l,int r,int x)
{
    if(r<l)return 0;
    if(l==r)return 1;
    if(dp[l][r][x]!=-1)return dp[l][r][x];
    int t=max(dfs(l+1,r,x),dfs(l,r-1,x));
    if(s[l]==s[r])t=max(t,dfs(l+1,r-1,x)+2);
    else if(x)t=max(t,dfs(l+1,r-1,x-1)+2);
    return dp[l][r][x]=t;
}
int main()
{
    cin>>s>>K;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,s.size()-1,K)<<endl;
    return 0;
}