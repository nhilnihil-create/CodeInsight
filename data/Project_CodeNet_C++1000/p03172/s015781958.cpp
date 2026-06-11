#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ff first
#define ss second
#define vi vector<ll>
#define mod 1000000007
#define MOD 1000000007
#define full(a) a.begin(),a.end()
#define inf INT_MAX
#define minf INT_MIN
#define dd double
#define fori(x,n) for(ll i=x;i<n;i++)
#define modd 998244353
#define umap unordered_map<ll,ll>

ll a[101];

ll fun(ll n,ll k){
  ll dp[n+2][k+2];

  for(int j=0;j<=k;j++)     //base case
    dp[0][j]=(j>a[0]?0:1);

  for(int i=1;i<n;i++)     // distributing among other children also
    for(int j=0;j<=k;j++)
      if(j==0)dp[i][j]=dp[i-1][j];   // if no candies left
      else dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j]%mod-(j-a[i]-1>=0?dp[i-1][j-a[i]-1]:0)%mod +mod)%mod;


    return dp[n-1][k];


}

int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n,k;
    cin>>n>>k;
   
    fori(0,n)cin>>a[i];
 
    
    cout<<fun(n,k)<<"\n";





    
  
    
    
 
return 0;
}    