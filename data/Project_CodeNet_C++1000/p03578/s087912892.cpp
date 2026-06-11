#include <bits/stdc++.h>
using namespace std;

map<int, int> H;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		H[u]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int u; cin >> u;
		if (H.count(u) && H[u] > 0) H[u]--;
		else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	
	return 0;
}
