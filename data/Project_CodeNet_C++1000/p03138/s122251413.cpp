#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100001
#define int ll
int N,K,A[maxn];

int dp[maxn][2];
int num[50][2];
bool vis[maxn][2];

int dpf(int idx,bool same){
	if (vis[idx][same]) return dp[idx][same];
	vis[idx][same] = 1;
	if (idx < 0) return 0;
	
	int lim = 1;
	
	bool val = ((ll)K & ((ll)1<<(ll)idx));
	
	if (same){
		if (!val) lim = 0;
	}
	
	dp[idx][same] = 0;
	FOR(i,0,lim){
		if (idx == 0) dp[idx][same] = max(dp[idx][same],(ll)num[idx][(i+1)%2] * (ll)((ll)1<<(ll)idx));
		else dp[idx][same] = max(dp[idx][same],dpf(idx-1,same && (i == val)) + (ll)num[idx][(i+1)%2] * (ll)((ll)1<<(ll)idx));
	}
	return dp[idx][same];
}
		
int32_t main(){
	fast;
	
	cin>>N>>K;
	
	FOR(i,0,N-1){
		cin>>A[i];
		
		FOR(j,0,40){
			if (A[i] & (ll)((ll)1<<(ll)j)) num[j][1]++;
			else num[j][0]++;
		}
	}
	
	int ans = 0;
	FOR(j,0,40) ans += (ll(1)<<(ll)j) * num[j][1];
	//cout<<ans;

	
	cout<<dpf(40,1);
	
	
}

