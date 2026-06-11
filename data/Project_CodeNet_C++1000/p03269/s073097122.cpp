#include "bits/stdc++.h"
using namespace std;

typedef pair<pair<int, int>, int> PP;

int main() {
	int L;
	cin >> L;
	int r = log2(L), count = 0;
	vector<PP> V;
	cout << r + 1 << " ";
	for (int i = 1; i <= r; i++) {
		V.push_back({ { i, i + 1 }, 0 });
		V.push_back({ {i, i + 1}, (int)pow(2, i - 1) });
	}
	for (int i = r; i >= 1; i--) {
		if (L - pow(2, i - 1) >= pow(2, r)) {
			V.push_back({ {i, r + 1}, L - (int)pow(2, i - 1) });
			L -= pow(2, i - 1);
			count++;
		}
	}
	cout << 2 * r + count << endl;
	for (auto it = V.begin(); it != V.end(); it++) {
		cout << it->first.first << " " << it->first.second << " " << it->second << endl;
	}
}