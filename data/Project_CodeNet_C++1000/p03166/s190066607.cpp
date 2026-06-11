#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

unsigned long long modpow(unsigned long long n, unsigned long long k, unsigned long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}
vector<vector<int>>adj(1e5+10);
vector<bool>vis(1e5+10,0);
stack<int>p;

void dfs(int v){
   if(vis[v]==1) return;
   vis[v] = 1;
   for(auto i:adj[v]) dfs(i);
   p.push(v);
}
void solve(){
     int n,m;
     cin >> n >> m;
     for(int i = 0;i<m;i++){
        int v,u;cin >> v >> u;
        adj[v].push_back(u);
     }
     for(int i = 1;i<=n;i++)
        dfs(i);
     vector<int>dp(n+1,0);
     while(!p.empty()){
        int v = p.top();p.pop();
        for(auto i:adj[v]){
           dp[i] = max(dp[i],dp[v]+1);
        }
     }
     int ans = 0;
     for(int i = 1;i<=n;i++){
        ans = max(ans,dp[i]);
     }
     cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}