#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
const ll N=4e5+5;
ll bexpo(ll x,ll n){
    if(n==0)return 1;
    else if(n%2==0)return bexpo(x*x,n/2);
    else return x*bexpo(x*x,(n-1)/2);
}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);} 
int Arr[N];
void initialize()
{
    for(int i = 0;i<N;i++)
    Arr[ i ] = i ;
}
int root(int i)
{
    while(Arr[ i ] != i)       
    {
     i = Arr[ i ];
    }
    return i;
}

void unio(int A ,int B)
{
    int root_A = root(A);       
    int root_B = root(B);  
    if(root_A<root_B)
        Arr[ root_A ] = root_B ;    
    else
        Arr[root_B]=root_A;
}
bool find(int A,int B)
{
    if( root(A)==root(B) )    
    return true;
    else
    return false;
}
ll dp[N];
vector<ll> adj[N];
ll dfs(ll node)
{
   if(dp[node]!=-1)
         return dp[node];
     ll mx=0;
    for(auto i:adj[node])
      mx=max(mx,dfs(i)+1);
     dp[node]=mx;
     return mx;
}
int main() {
FIO;
  ll n,m,ans=0,i;
  cin>>n>>m;
  ll x,y;
  while(m--)
  {
     cin>>x>>y;
     adj[x].pb(y);
  }
 for(i=1;i<=n;i++)
   dp[i]=-1;
  for(i=1;i<=n;i++)
    {
       ans=max(ans,dfs(i));
    }
    cout<<ans;
}