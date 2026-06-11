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

    int n,k;
    cin>>n>>k;
    int A[n+1];
    fn(i,n) cin>>A[i+1];
    A[0]=A[1];
    int dp[n+1];
    fill_n(dp,n+1,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+abs(A[i]-A[i-j]));
        }
    }
    cout<<dp[n];
}   