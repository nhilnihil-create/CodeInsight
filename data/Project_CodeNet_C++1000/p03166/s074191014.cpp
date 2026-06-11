#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define vl vector<ll>
#define pll pair<ll,ll>
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i= 0;i < a;i++)
#define rep1(i,a) for(ll i= 1;i < a;i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define pb push_back
#define sz(v) v.size()
#define all(a) a.begin(), a.end()
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1000005
#define MOD 1000000007
#define el "\n"
const ll INF = 2e9+5;

using namespace std;

ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll isPrime(ll n){if(n<=3) return 1;if(n%2==0||n%3==0) return 0;
for(ll j=5;j*j<=n;j+=6){if(n%j == 0||n%(j+2) == 0) return 0;}return 1;}

vector<ll>adj[100001];
ll dp[100001],vis[100001];
void dfs(ll node){
   vis[node] = 1;
   dp[node] = 0;
   for(auto i:adj[node]){
      if(vis[i] == 0) dfs(i);
      dp[node] = max(dp[node],1+dp[i]);
   }
}

void solve(){
   ll n,m;
   cin>>n>>m;
   rep(i,m){
      ll x,y;
      cin>>x>>y;
      adj[x].pb(y);
   }
   // vl vis(n,0);
   rep1(i,n+1){
      if(vis[i] == 0) dfs(i);
   }
   ll mx=-1;
   rep1(i,n+1){mx=max(mx,dp[i]);}
   cout<<mx;
}
 
int main() {
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r" , stdin);
      freopen("output.txt", "w" , stdout);
   #endif
   ios::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);   
   ll t;
   // cin>>t;
   t = 1;
   ll tc=0;
   while(tc++<t){
      // cout<<"Case #"<<tc<<": ";
      solve();
   }
   cerr<<"Time taken : "<<(double)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}