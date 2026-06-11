#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<ll, int> Pl;
typedef pair<int, int> P;

int n;
vector<int> g[100000];
bool used[100000];
int ct;
void dfs(int x){
	ct++;
	used[x]=1;
	for(auto y:g[x]){
		if(!used[y]) dfs(y);
	}
}
ll dist[100000];
int sz[100000];
void dfs2(int x){
	used[x]=1;
	sz[x]=1;
	for(auto y:g[x]){
		if(!used[y]){
			dist[y]=dist[x]+1;
			dfs2(y);
			sz[x]+=sz[y];
		}
	}
}
ll d2[100000];
void dfs3(int x){
	used[x]=1;
	for(auto y:g[x]){
		if(!used[y]){
			d2[y]=d2[x]-(ll)sz[y]+(ll)(n-sz[y]);
			dfs3(y);
		}
	}
}

int main()
{
	cin>>n;
	if(n<=4){
		cout<<-1<<endl;
		return 0;
	}
	ll d[100000];
	set<Pl> st;
	for(int i=0; i<n; i++){
		cin>>d[i];
		st.insert(Pl(d[i], i));
	}
	vector<P> ans;
	int s[100000];
	fill(s, s+n, 1);
	while(!st.empty()){
		auto itr=st.end(); itr--;
		int i0=(*itr).second;
		ll d0=(*itr).first;
		st.erase(itr);
		auto itr1=st.lower_bound(Pl(d0-(ll)(n-2*s[i0]), -1));
		if(itr1==st.end() || (*itr1).first!=d0-(ll)(n-2*s[i0])) continue;
		int i1=(*itr1).second;
		ans.push_back(P(i0, i1));
		g[i0].push_back(i1);
		g[i1].push_back(i0);
		s[i1]+=s[i0];
		if(ans.size()==n-1) break;
	}
	dfs(0);
	if(ct<n){
		cout<<-1<<endl;
		return 0;
	}
	fill(used, used+n, 0);
	dfs2(0);
	ll d0=0;
	for(int i=0; i<n; i++) d0+=dist[i];
	if(d[0]!=d0){
		cout<<-1<<endl;
		return 0;
	}
	d2[0]=d[0];
	fill(used, used+n, 0);
	dfs3(0);
	for(int i=1; i<n; i++){
		if(d[i]!=d2[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0; i<n-1; i++){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
	}
	return 0;
}