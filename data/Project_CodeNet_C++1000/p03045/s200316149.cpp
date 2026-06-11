#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, M;

vector<pii> e[100001];
int known[100001];


void dfs( int node, int parent_node ){
	known[node] = 1;
	for ( auto it : e[node] ){
		int next_node = it.first;
		if ( next_node == parent_node || known[next_node] )
			continue;
		dfs( next_node, node );
	}
}

int main(){
	cin >> N >> M;
	
	for ( int i = 0; i < M; i++ ){
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		z = z%2;
		
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	
	ll cost = 0;
	for ( int i = 0; i < N; i++ ){
		if ( !known[i] ){
			dfs( i, -1 );
			cost++;
		}
	}
	
	cout << cost << endl;
	
	return 0;
}

