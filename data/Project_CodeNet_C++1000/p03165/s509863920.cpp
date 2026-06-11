#include <bits/stdc++.h> 
using namespace std;
#define int long long int
#define float double
#define pb push_back
#define FF first
#define SS second
#define N 100005
#define MOD 1000000007
#define fn(i,n) for(int i=0;i<n;i++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>
#define mp make_pair
#define INF 9223372036854775807
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


signed main() 
{
    speed;
    //freopen("input.tXt","r",stdin);
    //freopen("output.tXt","w",stdout);

    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]==dp[i][j-1]) j--;
        else
        {
            ans+=s[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}   