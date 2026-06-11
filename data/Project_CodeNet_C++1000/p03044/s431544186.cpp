#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N;

vector<pii> e[100001];
int node_color[100001];

// 点0からの距離が偶数か奇数かで色を塗る
void dfs( int node, int parent_node, int color ){
	node_color[node] = color;
	for ( auto it : e[node] ){
		int next_node = it.first;
		if ( next_node == parent_node )
			continue;
		dfs( next_node, node, (color + it.second) % 2 );
	}
}

int main(){
	cin >> N;
	
	for ( int i = 0; i < N-1; i++ ){
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		w = w%2;
		
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	
	dfs( 0, -1, 0 ); 
	
	for ( int i = 0; i < N; i++ )
		cout << node_color[i] << "\n";
	
	return 0;
}

