#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint N;
P D[100005];
vector<llint> G[100005];
map<llint, vector<P> > mp;

P dfs(int v, int prev)
{
	llint d = 0, n = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == prev) continue;
		P res = dfs(G[v][i], v);
		n += res.second;
		d += res.first + res.second;
	}
	return make_pair(d, n);
}

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> D[i].first;
	for(int i = 1; i <= N; i++) D[i].second = i;
	llint d1 = D[1].first;
	sort(D+1, D+N+1), reverse(D+1, D+N+1);
	
	for(int i = 1; i <= N; i++){
		llint d = D[i].first, id = D[i].second;
		if(mp.count(d) == 0){
			if(i != N){
				llint p = d-N+2;
				if(p > d) continue;
				mp[p].push_back(make_pair(id, 1));
			}
		}
		else{
			llint x = 0;
			for(int j = 0; j < mp[d].size(); j++){
				G[id].push_back(mp[d][j].first);
				G[mp[d][j].first].push_back(id);
				x += mp[d][j].second;
			}
			x++;
			if(i != N){
				llint p = d-N+2*x;
				if(p > d) continue;
				mp[p].push_back(make_pair(id, x));
			}
		}
		
		/*for(auto it = mp.begin(); it != mp.end(); it++){
			cout << it->first << " ";
		}
		cout << endl;*/
	}
	vector<P> ans;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(i < G[i][j]) ans.push_back(make_pair(i, G[i][j]));
		}
	}
	if(ans.size() < N-1) cout << "-1" << endl;
	else{
		if(dfs(1, -1).first != d1) cout << -1 << endl;
		else for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}