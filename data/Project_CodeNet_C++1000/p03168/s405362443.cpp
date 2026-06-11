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

    int n;
    cin>>n;
    float A[n+1];
    for(int i=1;i<=n;i++) cin>>A[i];

    float dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j==0) dp[i][j]=(1-A[i])*dp[i-1][j];
            else dp[i][j]=A[i]*dp[i-1][j-1]+(1-A[i])*dp[i-1][j];
        }
    }
    float ans=0;
    for(int j=0;j<=n;j++) if(j>n-j) ans+=dp[n][j];
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl;
}   