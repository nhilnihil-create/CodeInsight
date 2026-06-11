#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	vector<string> W(N);
	for (int i = 0; i < N; ++i) {
		cin >> W[i];
	}

	char latest = W[0][W[0].size()-1];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (W[i] == W[j]) {
				cout << "No" << endl;
				return 0;
			}
		}

		if (W[i][0] != latest) {
			cout << "No" << endl;
			return 0;
		}
		latest = W[i][W[i].size() - 1];
	}

	cout << "Yes" << endl;
	return 0;
}
