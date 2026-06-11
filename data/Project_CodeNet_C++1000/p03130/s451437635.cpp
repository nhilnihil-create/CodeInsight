# include <bits/stdc++.h>
 
using namespace std;

vector < int > adj[5];

int main() {
	int cnt1 = 0, cnt = 0;
	for ( int i = 0; i < 3; i++ ) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for ( int i = 1; i <= 4; i++ ) {
		if ( (int)adj[i].size() == 1 ) cnt1++;
		else if ( (int)adj[i].size() == 2 ) cnt++;
		else {
			cout << "NO";
			return 0;
		}
	}
	if ( cnt1 == 2 && cnt == 2 ) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}