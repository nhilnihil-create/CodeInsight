#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll A,ll B) {if(!B)return A;return gcd(B,A%B);}
ll a[17][17];
ll dp[(1<<16)+1];
ll pre[(1<<16)+1];
int n;
void rec(int mask,int g_mask,vector<ll>&taken,int cnt){
	if(cnt == (int)(taken.size())){
		dp[mask^g_mask] = max(dp[mask^g_mask],dp[mask]+pre[g_mask]);
	}else{
	rec(mask,g_mask,taken,cnt+1);
	rec(mask,g_mask^(1<<taken[cnt]),taken,cnt+1);
}
}
int main()
{
	owo
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<n);i++)dp[i] = -INF;
	dp[0] = 0;
	for(int mask=0;mask<(1<<n);mask++){
		vector<ll>group;
		for(int j=0;j<n;j++){
			if(mask&(1<<j))group.pb(j);
		}
		int sz = group.size();
		for(int i=0;i<sz;i++)
			for(int j=i;j<sz;j++)
			    pre[mask]+=a[group[i]][group[j]];
		//cout<<pre[mask]<<'\n';
	}
	for(int mask=0;mask<(1<<n);mask++){
		vector<ll>taken;
		for(int j=0;j<n;j++){
			if(!(mask & (1<<j)))taken.pb(j);
		}
		rec(mask,0,taken,0);
		//cout<<dp[mask]<<'\n';
	}
	cout<<dp[(1<<n)-1];
}
