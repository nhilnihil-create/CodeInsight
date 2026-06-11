#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int sum = c;
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			sum += x * b[j];
		}
		if (sum > 0) {
			cnt++;
		}
	}
	
	cout << cnt;
}

















