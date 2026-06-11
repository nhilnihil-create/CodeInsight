#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define ll long long int
#define ull unsigned long long int
#define inf LONG_MAX
#define mod 100000007
using namespace std;
int dp[3001][3001];
string s,t;
string ans="";
void find_lcs(int i,int j)
{
    if(dp[i][j]==0)
        return;
    if(dp[i-1][j]==dp[i][j-1] && dp[i][j-1]==dp[i-1][j-1])
    {
        if(dp[i][j]>dp[i-1][j-1])
            ans+=t[j-1];
        find_lcs(i-1,j-1);
    }
    else if(dp[i-1][j]>dp[i][j-1])
        find_lcs(i-1,j);
    else
        find_lcs(i,j-1);
}
int main()
{
    fast_io
    cin>>s>>t;
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=t.length();j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    find_lcs(s.length(),t.length());
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
