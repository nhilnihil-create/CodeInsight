// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int go;
	
	if(n & 1) {
		go = n;
	}
	else {
		go = n + 1;
	}

	vector<pair<int,int>> edges;

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(j + i == go) continue;
			edges.push_back(make_pair(i, j));
		}
	}

	cout << edges.size() << "\n";

	for(auto x : edges) cout << x.first << " " << x.second << "\n";
	
	return 0;
}
