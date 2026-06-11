#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
const ll MAX_N=2e5;
ll N;
vector<ll> G[MAX_N];
ll dst[MAX_N];
void caldst(ll s,ll d,ll p){
	dst[s]=d;
	for(auto e:G[s]){
		if(e!=p){
			caldst(e,d+1,s);
		}
	}
}
ll dia(){
	caldst(0,0,-1);
	ll v=0;
	REP(i,N){
		if(dst[i]>dst[v]){
			v=i;
		}
	}
	caldst(v,0,-1);
	ll ans=0;
	REP(i,N){
		ans=max(ans,dst[i]);
	}
	return ans;
}
	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	REP(i,N-1){
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout<<(dia()%3==1?"Second":"First")<<endl;
}