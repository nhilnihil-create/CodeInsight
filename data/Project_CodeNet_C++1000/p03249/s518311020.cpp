// In the name of God

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

pair<ll,int> p[maxn];
map<ll,vector<int> >mp;
int par[maxn],SZ[maxn];
vector<int>v[maxn];

pair<ll,int> dfs(int u,int par=-1){
    ll A=0;
    int B=1;
    for(int y:v[u]){
	if(y!=par){
	    pair<ll,int>p=dfs(y,u);
	    B+=p.S;
	    A+=p.F+p.S;
	}
    }
    return {A,B};
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>p[i].F;
	p[i].S=i;
    }
    sort(p+1,p+n+1);
    for(int i=n;i>=1;i--){
	SZ[p[i].S]=1;
	if(mp.count(p[i].F)){
	    for(int id:mp[p[i].F]){
		par[id]=p[i].S;
		SZ[p[i].S]+=SZ[id];
	    }
	    mp.erase(p[i].F);
	}
	mp[p[i].F+2*SZ[p[i].S]-n].PB(p[i].S);
    }
    for(int i=1;i<=n;i++){
	if(par[i]==0 && i!=p[1].S){
	    return cout<<-1<<endl,0;
	}
	else if(par[i]!=0){
	    v[par[i]].PB(i);
	}
    }
    if(dfs(p[1].S).F!=p[1].F){
	return cout<<-1<<endl,0;
    }
    for(int i=1;i<=n;i++){
	if(i==p[1].S)continue;
	cout<<i<<" "<<par[i]<<"\n";
    }
    return 0;
}
