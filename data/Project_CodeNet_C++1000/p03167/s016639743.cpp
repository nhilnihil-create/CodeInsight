#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
const ll N=1e3+5;
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
ll dp[N][N];
vector<ll> adj[N];
string a[N];
ll h,w;
ll dfs(ll i,ll j)
{
   if(i>h || j>w)
    return 0;
    if(dp[i][j]!=-1)
         return dp[i][j];
       if(i==h && j==w)
    return 1;
       ll cnt=0;
    for(ll x=0;x<=1;x++)
    {
      for(ll y=0;y<=1;y++)
      {
        if(x!=y && a[i+x-1][j+y-1]=='.')
          cnt=(cnt+dfs(i+x,j+y))%mod;
      }
    }
    return dp[i][j]=cnt;
}
int main() {
FIO;
  cin>>h>>w;
  ll i,j;
  for(i=0;i<h;i++)
  {
        cin>>a[i];
  }
  for(i=1;i<=h;i++)
      for(j=1;j<=w;j++)
        dp[i][j]=-1;
  cout<<dfs(1,1);
}