#include<bits/stdc++.h>
using namespace std;
const int N=100100;
typedef long long ll;
ll sum[N];int sz[N],n;
map<ll,int>mp;
vector<pair<int,int> >egs;
void gofail(){cout<<-1<<'\n';exit(0);}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){ll x;cin>>x;mp[x]=i;sz[i]=1;sum[i]=0;}
	for(;!mp.empty();){
		ll u=mp.rbegin()->first;int v=mp.rbegin()->second;mp.erase(u);
		if(sz[v]==n){
			if(sum[v]!=u)gofail();
			sort(egs.begin(),egs.end());
			for(auto&i:egs)cout<<i.first<<' '<<i.second<<'\n';
			return 0;
		}else{
			ll w=u+2*sz[v]-n;
			if(!mp.count(w))gofail();
			int x=mp[w];sz[x]+=sz[v];sum[x]+=sum[v]+sz[v];
			egs.emplace_back(min(v,x),max(v,x));
		}
	}
	return 0;
}
