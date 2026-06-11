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
    int A[n+1],B[n+1],C[n+1];
    int dp[n+1][3];
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>A[i]>>B[i]>>C[i];
        dp[i][0]=max(dp[i-1][1]+A[i],dp[i-1][2]+A[i]);
        dp[i][1]=max(dp[i-1][0]+B[i],dp[i-1][2]+B[i]);
        dp[i][2]=max(dp[i-1][0]+C[i],dp[i-1][1]+C[i]);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}   