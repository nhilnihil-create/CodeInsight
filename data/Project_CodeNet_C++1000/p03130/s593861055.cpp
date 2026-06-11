#include "bits/stdc++.h"
using namespace std;

int main() {
	int a, b, p[4] = { 0 };
	bool check = true;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		p[a - 1]++;
		p[b - 1]++;
	}
	for (int i = 0; i < 4; i++) {
		if (p[i] == 0 || p[i] > 2) {
			check = false;
		}
	}
	if (check) cout << "YES";
	else cout << "NO";
}