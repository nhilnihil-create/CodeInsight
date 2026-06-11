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

int n,m;
string s[1001];
int dp[1001][1001];

int recmemo(int i,int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return 1;
    int a=0;
    if(i>0 && s[i-1][j]=='.') a=recmemo(i-1,j);
    int b=0;
    if(j>0 && s[i][j-1]=='.') b=recmemo(i,j-1);
    dp[i][j]=(a+b)%MOD;
    return dp[i][j];
}


signed main() 
{
    speed;
    //freopen("input.tXt","r",stdin);
    //freopen("output.tXt","w",stdout);

    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>s[i];
    cout<<recmemo(n-1,m-1);
}   