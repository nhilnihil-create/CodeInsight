#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
lli DFS(vector<lli> adj[], lli index, bool *visited, lli *DP) {
	if(visited[index]) {
		return DP[index];
	}
	visited[index] = true;
	lli output = 0;
	for(lli i = 0; i < adj[index].size(); i++) {
		output = max(output, 1 + DFS(adj, adj[index][i], visited, DP));
	}
	DP[index] = output;
	return output;
}
main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    lli N, M;
    cin >> N >> M;
    vector<lli > adj[N + 1];
    for(lli i = 0; i < M; i++) {
    	lli X, Y;
    	cin >> X >> Y;
    	adj[X].push_back(Y);
	}
	bool *visited = new bool[N + 1];
	lli *DP = new lli[N + 1];
	for(lli i = 0; i <= N; i++) {
		visited[i] = false;
		DP[i] = 0;
	}
	lli output = 0;
	for(lli i = 1; i <= N; i++) {
		if(!visited[i]) {
			output = max(output, DFS(adj, i, visited, DP));
		}
	}
	cout << output << '\n';
  	delete[] visited;
  	delete[] DP;
}

