#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int ll 
#define FOR(i,s,e) for(ll i = s; i <= (ll)e; ++i)
#define DEC(i,s,e) for(ll i = s; i >= (ll)e; --i)
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#define db(x) cerr << #x << "=" << x << "\n"
#define db2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << "\n"
#define db3(a,b,c) cerr<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<"\n"
#define dbv(v) cerr << #v << ":"; for (auto ite : v) cerr << ite << ' '; cerr <<"\n"
#define dbvp(v) cerr << #v << ":"; for (auto ite : v) cerr << "{"  << ite.f << ',' << ite.s << "} "; cerr << "\n"
#define dba(a,ss,ee) cerr << #a << ":"; FOR(ite,ss,ee) cerr << a[ite] << ' '; cerr << "\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long 
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define reach cerr << "LINE: " << __LINE__ << "\n";
typedef pair <ll, ll> pi;
typedef tuple<ll,ll,ll> ti3;
string cts(char x) {string t(1,x); return t;}
ll rand(ll a, ll b) { return a + rng() % (b-a+1); }
const int MOD = 1e9 + 7;
const int inf = (int)1e9 + 500;
const long long oo = (ll)1e18 + 500;
template <typename T> void chmax(T& a, T b) { a = max(a, b); }
template <typename T> void chmin(T& a, T b) { a = min(a, b); }
const int MAXN = 100005;
#ifndef LOCAL
#define cerr if(0)cout
#endif
int n; 
vector <int> V[MAXN];
int dp[MAXN][2];
//0-> white
//1-> black
ll dfs(int x, int p, int color) {
	if(dp[x][color]!=-1)return dp[x][color];
	dp[x][color] = 1;
	if(V[x].size()==1&&p!=-1)return 1;
	if(color == 0) {
		for(auto v:V[x]) if(v!=p){
			dp[x][0]*=(dfs(v,x,0) + dfs(v,x,1));
			dp[x][color]%=MOD;
		}
		return dp[x][color];
	} else {
		for(auto v:V[x]) if(v!=p){
			dp[x][color]*=dfs(v,x,0);
			dp[x][color]%=MOD;
		}
		return dp[x][color];
	}
}

		

int32_t main() 
{
	IAMSPEED
	memset(dp,-1,sizeof dp);
	cin >> n;
	FOR(i,1,n-1) {
		int x,y; cin >> x >> y;
		V[x].pb(y);
		V[y].pb(x);
	}
	if(n==1) {
		cout << 2;
		exit(0);
	}
	
	cout << (dfs(1,-1,0) + dfs(1,-1,1)) %MOD;
}

