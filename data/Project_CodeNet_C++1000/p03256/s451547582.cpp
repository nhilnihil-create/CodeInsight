// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+10, maxm=5e4+10, lg=21, mod=998244353, inf=1e18;

ll n,m,d[2][maxn];
vector<ll> g[maxn];
bool rem[maxn],F=1;
string S;
set<pll> s[2];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>S;
	while(m--){
		ll v,u; cin>>v>>u; v--,u--;
		d[S[v]-'A'][u]++, d[S[u]-'A'][v]++;
		g[v].pb(u), g[u].pb(v);
	}
	for(int i=0;i<n;i++) s[0].insert({d[0][i],i}), s[1].insert({d[1][i],i});
	while(F){
		F=0;
		for(int b:{0,1})if(!s[b].empty()){
			auto it=s[b].begin();
			if((it->F)==0){ F=1;
				ll v=it->S; bool c=S[v]-'A';
				rem[v]=1;
				s[0].erase({d[0][v],v});
				s[1].erase({d[1][v],v});
				for(auto u:g[v])if(!rem[u]){
					s[c].erase({d[c][u],u});
					s[c].insert({--d[c][u],u});
				}
			}
		}
	}
	if(!s[0].empty()) cout<<"Yes";
	else cout<<"No";
	
	return 0;
}



 
