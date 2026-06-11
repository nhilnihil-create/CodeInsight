#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define int long long int
#define read(a) int a; cin >> a;
#define readb(a, b) int a, b; cin >> a >> b;
#define readc(a, b, c) int a, b, c; cin >> a >> b >> c;
#define readarr(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define readmat(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define print(a) cout << a << endl;
#define printarr(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printv(v) for (int i: v) cout << i << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define vvi vector <vi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll MOD = 1e9+7;
const ll inf = 1e18;
const ll p = 998244353;
vector<int> visited;
vector<int> group;
vector<vector<int> > adj;
void dfs(int s,int count)
{
	if(visited[s])return;
	visited[s]=1;
	group[s]=count;
	for(int i=0;i<sz(adj[s])-1;i++)
	{
		if(!visited[adj[s][i]])
		dfs(adj[s][i],count);
	}
}
//matrix of 1 and 0 ,1 island count the number of groups of islands
//dp bitmask implementation
// 4 more dp problems
signed main() 
{
 int n,k;
 cin>>n>>k;
 int a[n+1];
 for(int i=1;i<=n;i++)
 cin>>a[i];
 int dp[n+1][k+1];
 int pref[n+1][k+1];
 for(int i=0;i<=n;i++)
 {
 	for(int j=0;j<=k;j++)
 	{
 	pref[i][j]=0;
 	dp[i][j]=0;	
    }
 }
 for(int i=0;i<=n;i++)
 {
 dp[i][0]=1;
 pref[i][0]=1;	
 }
 for(int i=1;i<=n;i++)
 {
 	for(int j=1;j<=k;j++)
 	{
 	 pref[i-1][j]=(pref[i-1][j-1]+dp[i-1][j])%MOD;
 	 pref[i-1][j]=pref[i-1][j]%MOD;
 	  if(j<=a[i])
	  dp[i][j]=pref[i-1][j];
	  else
	  dp[i][j]=pref[i-1][j]-pref[i-1][j-a[i]-1];
	  if(dp[i][j]<0)dp[i][j]+=MOD;
	  dp[i][j]%=MOD;
	  //cout<<dp[i][j]<<" ";	
	}
	//cout<<endl;
 }
 cout<<dp[n][k]<<endl;
}