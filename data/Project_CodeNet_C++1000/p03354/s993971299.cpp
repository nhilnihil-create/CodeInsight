#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define pb push_back

ll N,M;
ll p[100005];
ll pp[100005];
ll ans;
ll gp;
ll chk[100005];
vector<vector<ll> > vv(100005);

void dfs(ll node){
	if(chk[node]) return;
	chk[node]=gp;
	rep(i,vv[node].size()){
		ll to=vv[node][i];
		dfs(to);
	}
	return;
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;

rep(i,N){
	cin>>p[i];
	pp[p[i]]=i+1;
}

rep(i,M){
	ll x,y;
	cin>>x>>y;
	vv[x].pb(y);
	vv[y].pb(x);
}

for(ll i=1; i<=N; i++){
	if(chk[i]==0){
		gp++;
		dfs(i);
	}
}

for(ll i=1; i<=N; i++){
	if(chk[i]==chk[pp[i]]) ans++;
}

cout<<ans<<endl;

}
	
