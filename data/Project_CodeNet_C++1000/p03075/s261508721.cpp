#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	vector<int> v(5);
	for (int i = 0; i < 5; i++) {
		cin >> v[i];
	}

	int k;
	cin >> k;

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			int d = abs(v[i] - v[j]);
			if (d > k) {
				cout << ":(" << endl;
				return 0;
			}
		}
	}

	cout << "Yay!" << endl;
}