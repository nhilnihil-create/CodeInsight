#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	map<int, int> M;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		M[x]++;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (M[x] == 0) {
			cout << "NO" << endl;
			return 0;
		}
		M[x]--;
	}
	cout << "YES" << endl;
	return 0;
}

