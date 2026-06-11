#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	int in1;
	map <int, int> an;
	for (int i = 0; i < n; i++) {
		cin >> in1;
		an[in1]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> in1;
		an[in1]--;
		if (an[in1] < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}