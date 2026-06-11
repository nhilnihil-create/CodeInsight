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
    int A[n];
    fn(i,n) cin>>A[i];

    int dp[k+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-A[j]>=0 && dp[i-A[j]]==0)
            {
                dp[i]=1;
                break;
            }
        }
    }
    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}   