#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int w;
			cin >> w;
			w--;
			v[w]++;
		} 
	}	  
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (v[i] == n) {
			cnt++;
		}
	}
	cout << cnt;
}
