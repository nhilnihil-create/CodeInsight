#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int  p = 5;
	vector<int> c(p);
	for (int i = 0; i < p; i++) {
		cin >> c[i];
	}
	int k; cin >> k;
	bool can = true;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			if (i == j) continue;
			if (k < abs(c[i] - c[j])) {
				can = false;
			}
		}
	}
	if (can) cout << "Yay!" << endl;
	else cout << ":(" << endl;

	return 0;
}