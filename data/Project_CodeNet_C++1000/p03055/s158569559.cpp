#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int d[N];
vector<int> gr[N];
void dfs(int cur, int parent){
	for (int adj : gr[cur]){
		if (adj != parent){
			d[adj] = d[cur] + 1;
			dfs(adj,cur);
		}
	}
}

int main(){
	int n; 
  	cin >> n;
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	
	dfs(0,-1);
	int edge = max_element(d,d+n) - d;
	d[edge] = 0;
	dfs(edge, -1);
	int ans = *max_element(d,d+n);
	if (ans % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
	return 0;
}