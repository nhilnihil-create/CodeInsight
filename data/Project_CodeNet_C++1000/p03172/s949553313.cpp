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
const int MAXN = -1;
#ifndef LOCAL
#define cerr if(0)cout
#endif
int A[105];
int dp[105][100005]; //ways to get to idx with j cookies eaten
int sum[100005];

ll rsq(int x, int y) { return ((MOD+sum[y] - sum[x-1])%MOD+MOD)%MOD; }

int32_t main() 
{
	IAMSPEED
	int n, k; cin >> n >> k;
	FOR(i,1,n)cin>>A[i];
	dp[0][0] = 1;
	FOR(i,1,n) {
		memset(sum,0,sizeof sum);
		sum[0]=1;
		FOR(j,1,k) {
			sum[j]=sum[j-1]+dp[i-1][j];
			sum[j]%=MOD;
		}
		dp[i][0]=1;
		FOR(j,1,k) {
			if(j-A[i]<=0)dp[i][j]=sum[j];
			else dp[i][j]=rsq(j-A[i],j);
			dp[i][j]%=MOD;	
		}
	}
	cout << dp[n][k];
			
}

