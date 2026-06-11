#include<cstdio>
#include<vector>
#include<utility>
#include<stack>
#include<cstring>
using namespace std;

int main(){
    unsigned N;
    scanf("%u", &N);
    vector<pair<unsigned, bool> > adj[N];
    for (size_t i = 1; i < N; i++){
        unsigned u, v, w;
        scanf("%u %u %u", &u, &v, &w);
        u--;v--;
        bool tmp = w&1;
        adj[u].push_back(make_pair(v, tmp));
        adj[v].push_back(make_pair(u, tmp));
    }
    int color[N];
    memset(color, -1, sizeof color);
	stack<unsigned> S;
	S.push(0);
	color[0] = 0;
	while(!S.empty()){
		unsigned u = S.top(); S.pop();
		for (unsigned i = 0; i < adj[u].size(); ++i){
			int v = adj[u][i].first;
			if(color[v] < 0){
				color[v] = color[u] ^ adj[u][i].second;
				S.push(v);
			}
		}
	}
    for (size_t i = 0; i < N; i++){
        printf("%d\n", color[i]);
    }
	return 0;
}