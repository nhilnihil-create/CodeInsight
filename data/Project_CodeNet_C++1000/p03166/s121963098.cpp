#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef pair<int,int> P;

int main(){
	int N,M;
	cin >> N >> M;
	vector<vector<P>> edge(N+1);
	vector<int> check(N+1);
	rep(i,M){
		int x,y;
		cin >> x >> y;
		check[y]++;
		edge[x].push_back(make_pair(x,y));
	}

	queue<int> que;
	for(int i=1; i<=N; i++){ if(check[i]==0) { que.push(i); check[i]--; } }

	vector<P> sorted;
	while( !que.empty() ){
		int node = que.front(); que.pop();
		for(int i=0; i<(int)edge[node].size(); i++){
			check[edge[node][i].second]--;
			if(check[edge[node][i].second] == 0){ 
				que.push(edge[node][i].second); 
				check[edge[node][i].second]--;
			}
			sorted.push_back(edge[node][i]);
		}
	}

	vector<int> path(N+1);
	for(P p : sorted){
		path[p.second] = max(path[p.second], path[p.first]+1);
	}
	cout << *max_element(path.begin(),path.end()) << endl;
	return 0;
}

