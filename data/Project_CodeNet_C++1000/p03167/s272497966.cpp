#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
const int N=1e5+1;
const int INF=1e9+7;

int32_t main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 int n,m; cin>>n>>m;
 char A[n][m];
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         cin>>A[i][j];
     }
 }
 int dp[n][m];
 memset(dp,0,sizeof(dp));
 dp[0][0]=1;
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(A[i][j]=='.')
         {
             if(i==0 && j>0){dp[i][j]=(dp[i][j-1])%INF;}
             else if(j==0 && i>0){dp[i][j]=(dp[i-1][j])%INF;}
             else if(i>0 && j>0){dp[i][j]=(dp[i-1][j]+dp[i][j-1])%INF;}
         }
     }
 }
 cout<<dp[n-1][m-1];
}