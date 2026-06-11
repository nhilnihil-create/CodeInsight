#include<bits/stdc++.h>
using namespace std;
vector<int> adj[5];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<3;i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<4;i++){
		if(adj[i+1].size() > 2){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}