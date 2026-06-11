#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

pair<ll, int> p[100010]={};
int nd[100010];
vector<vector<int>> desc;
ll dep[100010]={};

ll dfs(int key){
	ll res=dep[key];
	for(int i=0; i<desc[key].size(); ++i){
		dep[desc[key][i]]=dep[key]+1;
		res += dfs(desc[key][i]);
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	for(int i=1; i<=N; ++i){
		ll D;
		cin >> D;
		p[i-1]=make_pair(D, i);
	}
	sort(p, p+N, greater<>());
	desc.resize(N+1);
	for(int i=1; i<=N; ++i) nd[i]=1;
	for(int i=0; i<N-1; ++i){
		int ng=i, ok=N-1;
		ll key=p[i].first-(N-nd[p[i].second]*2);
		while(ng+1<ok){
			int mid=(ng+ok)/2;
			if(p[mid].first<=key) ok=mid;
			else ng=mid;
		}
		if(p[ok].first!=key){
			cout << -1 << endl;
			return 0;
		}
		desc[p[ok].second].emplace_back(p[i].second);
		nd[p[ok].second] += nd[p[i].second];
	}
	if(dfs(p[N-1].second)!=p[N-1].first){
		cout << -1 << endl;
		return 0;
	}
	for(int i=1; i<=N; ++i){
		for(int j=0; j<desc[i].size(); ++j){
			cout << i << ' ' << desc[i][j] << endl;
		}
	}
	return 0;
}