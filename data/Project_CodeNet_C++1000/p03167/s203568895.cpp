#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mx 3000
ll n,m;
char gd[mx][mx];
ll solve(ll n,ll m){
   ll dp[n+1][m+1];
    dp[n][m]=1;
   for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
                if(i==n&& j==m)continue;
             if(gd[i][j]=='#')
                dp[i][j]=0;
              else  dp[i][j]=(((i==n)?0:dp[i+1][j])+((j==m)?0:dp[i][j+1]))%mod;

        }
   }
  /* for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){
    cout<<dp[i][j]<<" ";}cout<<endl;
   }*/
   return dp[1][1];
}
int main()
{
    FIO;
    ll c,d,e,f=0,sum=0,ans,ck,k,p,q,r,t,add=0,w,x,y,z;
    cin>>n>>m;

    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {cin>>gd[i][j];}
   ck= solve(n,m);
    cout<<ck<<endl;

    return 0;
}