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
    int A[n+1];
    fn(i,n) cin>>A[i+1];
    int dp[n+1];
    dp[1]=0;
    if(n==1) 
    {
        cout<<0<<endl;
        return 0;
    }
    dp[2]=abs(A[2]-A[1]);
    for(int i=3;i<=n;i++) dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]),dp[i-2]+abs(A[i]-A[i-2]));
    cout<<dp[n]<<endl;
}   