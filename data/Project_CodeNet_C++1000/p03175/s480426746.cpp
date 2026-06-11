#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
typedef long long ll;
const ll MAXN = 2e5 + 2;
const ll MAXK = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll MODH = 1e9 + 9;
const int MAXLG = 20;
const long double PI = acos(-1);
const ll p = 41;
const long double EPS = 1e-4;
#define x first
#define y second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}
ll binpow(ll a, ll b, ll m) {a %= m;ll res = 1;while (b > 0) {if (b & 1){res = res * a % m;}a = a * a % m;b >>= 1;
}return res;}


vector<int> g[MAXN];
ll dp[MAXN][3];

void dfs(int u,int p,int col)
{

 
   dp[u][0] = dp[u][1] = 1;
   for(auto &k : g[u])
   {
   	if(k == p)
   		 continue; 
   		dfs(k,u,1);
   		 
   	dp[u][0]*=(dp[k][1] + dp[k][0]);
   	dp[u][1]*=dp[k][0];
   	dp[u][0]%=MOD;
   	dp[u][1]%=MOD;
   }
   
  
   
}



int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i = 0 ; i < n - 1; i++)
  {
  	int u,v;
  	cin >> u >> v;
  	g[u].push_back(v);
  	g[v].push_back(u);
  }
  dfs(1,0,-1);
  cout << (dp[1][0] + dp[1][1])%MOD;

  
 
  
}