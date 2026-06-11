#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, V, C;
	cin >> N;
	int total = 0;
	vector<int> value(N);
	vector<int> cost(N);
	for (int i = 0; i < N; i++) {
		cin >> V;
		value.at(i) = V;
	}
	for (int j = 0; j < N; j++) {
		cin >> C;
		cost.at(j) = C;
	}
	for (int k = 0; k < N; k++) {
		if (value.at(k) > cost.at(k)) {
			total += value.at(k) - cost.at(k);
		}
		else {
			continue;
		}
	}
	cout << total << endl;
}