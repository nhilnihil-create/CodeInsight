#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, T, c, t;
	cin >> N >> T;
	int cost = 10000;
	for (int i = 0; i < N; i++) {
		cin >> c >> t;
		if (cost > c && T >= t) {
			cost = c;
		}
	}
	if (cost == 10000) {
		cout << "TLE" << endl;
	}
	else {
		cout << cost << endl;
	}
}
