#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
pair<ll,int> p[100010],q[100010];
map<ll,vector<pair<int,int>>> mp;
vector<pair<int,int>> ans;
vector<int> G[100010];
ll d[100010],j[100010],e[100010],n;
int dfs(int s,int p){
	int res = 1;
	for(int v: G[s]){
		if(v!=p){
			d[v] = d[s] + 1;
			res += dfs(v,s);
		}
	}
	return j[s] = res;
}

void solve(int s, int p, ll val){
	for(int v:G[s]){
		if(v!=p){
			e[v] = val + n - 2*j[v];
			solve(v,s,e[v]);
		}
	}
}

int main(){
	int i;
	cin >> n;
	for(i=0;i<n;i++){
		ll d; cin >> d;
		p[i] = {d,i};
	}
	sort(p,p + n);
	for(i=n-1;i>=0;i--){
		if(mp.find(p[i].first)==mp.end()){
			mp[p[i].first - n + 2].push_back({p[i].second,1});
		}else{
			int sum = 1;
			for(auto x:mp[p[i].first]){
				sum += x.second;
				ans.push_back({x.first,p[i].second});
			}
			mp[p[i].first - n + 2*sum].push_back({p[i].second,sum});
		}
	}
	if(ans.size()==n-1){
		for(i=0;i<n;i++) d[i] = -1;
		for(i=0;i<n-1;i++){
			int f = ans[i].first,s = ans[i].second;
			G[f].push_back(s); G[s].push_back(f);
		}
		d[0] = 0; dfs(0,-1);
		ll m = 0;
		for(i=0;i<n;i++){
			if(d[i]==-1){
				cout << -1 << endl;
				return 0;
			}
			m += d[i];
		}
		e[0] = m; solve(0,-1,m);
		for(i=0;i<n;i++){
			q[i] = {e[i],i};
		}
		sort(q,q + n);
		for(i=0;i<n;i++){
			if(p[i]!=q[i]){
				cout << -1 << endl;
				return 0;
			}
		}
		for(i=0;i<ans.size();i++){
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
		}
	}else{
		cout << -1 << endl;
	}
}