#include<cstdio>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> Adjacent[N];
	pair<int, int> Edge[M];
	for (int i = 0; i < M; ++i){
		scanf("%d %d", &Edge[i].first, &Edge[i].second);
		Edge[i].first--;Edge[i].second--;
		Adjacent[Edge[i].first].push_back(Edge[i].second);
		Adjacent[Edge[i].second].push_back(Edge[i].first);
	}
	int answer = 0;
	bool has_been_discovered[N];
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j) has_been_discovered[j] = false;
		stack<int> S;
		S.push(Edge[i].first);
		has_been_discovered[Edge[i].first] = true;
		bool is_bridge = true;
		while(!S.empty()){
			int u = S.top(); S.pop();
			for (int j = 0; j < Adjacent[u].size(); ++j){
				int v = Adjacent[u][j];
				if(u == Edge[i].first && v == Edge[i].second) continue;
				if(v == Edge[i].second){
					is_bridge = false;
					break;
				}
				if(!has_been_discovered[v]){
					has_been_discovered[v] = true;
					S.push(v);
				}
			}
			if(!is_bridge) break;
		}
		if(is_bridge) answer++;
	}
	printf("%d\n", answer);
	return 0;
}