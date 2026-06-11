#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
const ll MAX_N=5000,INF=1e18;
ll N,A,B,memo[MAX_N+1][MAX_N*2+1],q[MAX_N];
ll dfs(ll n,ll x){
	if(n==N){
		return 0;
	}
	if(memo[n][x]!=-1){
		return memo[n][x];
	}
	ll ret=INF,x2;
	if(q[n]*2+1>x){
		x2=(x+1)/2*2;
		ret=dfs(n+1,x2)+B;
		ret=min(ret,dfs(n+1,q[n]*2+1));
	}
	ret=min(ret,A+dfs(n+1,max(q[n]*2+2,(x+1)/2*2)));
	return memo[n][x]=ret;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>A>>B;
	REP(i,N){
		ll p;
		cin>>p;
		p--;
		q[p]=i;
	}
	memset(memo,-1,sizeof(memo));
	cout<<dfs(0,0)<<endl;
}