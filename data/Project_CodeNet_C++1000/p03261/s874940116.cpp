#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<string> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] == w[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (w[i][w[i].size() - 1] != w[i + 1][0]) {
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}