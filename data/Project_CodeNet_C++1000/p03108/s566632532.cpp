#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,M;
P bdg[100005];
ll siz[100005];
ll par[100005];
ll rnk[100005];
ll ans[100005];
bool love[100005];
void init(ll n){
	for(ll i=0; i<n; i++){
		par[i]=i;
		rnk[i]=0;
		siz[i]=0;
	}
}
ll find(ll x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}
void unite(ll x,ll y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]){
		siz[y]+=siz[x];
		par[x]=y;
	}else{
		siz[x]+=siz[y];
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}
bool same(ll x,ll y){
	return find(x)==find(y);
}
ll size(ll x) {
    return siz[find(x)];
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;
rep(j,M){
	cin>>bdg[j].first>>bdg[j].second;
	bdg[j].first--; bdg[j].second--;
}
ll unko=N*(N-1)/2;
init(N);
for(ll i=M-1;i>=0;i--){
	ll x=bdg[i].first,y=bdg[i].second;
	ans[i]=unko;
	if(same(x,y)){
		ll root=find(x);
		if(!love[x]){
			siz[root]++; love[x]=true;
		}
		if(!love[y]){
			siz[root]++; love[y]=true;
		}
	}else{
		ll root1=find(x); 
		ll root2=find(y); 
		if(!love[x]){
			siz[root1]++; love[x]=true;
		}
		if(!love[y]){
			siz[root2]++; love[y]=true;
		}
		unko-=siz[root1]*siz[root2];
		unite(x,y);
	}
}

rep(i,M) cout<<ans[i]<<endl;

}
	
