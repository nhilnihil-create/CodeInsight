#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n;
signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	vector<int>d(n);
	vector<int>w(n,1);
	map<int,int>mm;
	for(int i=0;i<n;i++){
		cin>>d[i];
		mm[d[i]]=i;
	}
	vector<pii>res;
	for(int iit=0;iit<n-1;iit++){
		auto it=mm.rbegin();
		int i=it->S;
		int x=d[i]-(n-w[i])+w[i];
		if(!mm.count(x)||mm[x]==i)return puts("-1"),0;
		int j=mm[x];
		res.pb(mp(i,j));
		w[j]+=w[i];
		mm.erase(--mm.end());
	}
	vector<int>v(n,-1);
	vector<vector<int> >G(n);
	v[0]=0;
	for(auto&p:res){
		G[p.F].pb(p.S);
		G[p.S].pb(p.F);
	}
	vector<int>qq(1,0);
	for(int b=0;b<(int)(qq.size());b++)
		for(int j:G[qq[b]])
			if(v[j]==-1){
				qq.pb(j);
				v[j]=v[qq[b]]+1;
			}
	if(accumulate(v.begin(),v.end(),0LL)!=d[0])return puts("-1"),0;
	for(auto&p:res)cout<<p.F+1<<' '<<p.S+1<<endl;
	return 0;
}
