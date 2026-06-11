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
 
vi sum;
ll dp[402][402];
 
ll fun(ll i,ll j){
  if(i==j)return 0;        // cost will be 0 for single element to form single slime
  if(dp[i][j]!=-1)return dp[i][j];
  ll res = sum[j]-(i>0?sum[i-1]:0);  // computing sum from i to j
  ll mini = 1e18;
 
  for(int r=i;r<=j-1;r++)
    mini=min(mini,fun(i,r)+fun(r+1,j));    // finding minimum cost for combining two slimes into one 
 
  return dp[i][j]= res + mini;
}
 
int32_t main() 
{ 
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll n;
    cin>>n;
    ll a[n];
    fori(0,n)cin>>a[i];
 
    memset(dp,-1,sizeof dp);
 
    sum.resize(n);
    sum[0]=a[0];
    fori(1,n)sum[i]=sum[i-1]+a[i];   //sum precomputation
 
 
    cout<<fun(0,n-1);
 
    
    
 
 
    
    
 
return 0;
}