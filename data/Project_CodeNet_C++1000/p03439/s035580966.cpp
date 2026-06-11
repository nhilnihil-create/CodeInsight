#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string V = "Vacant", M = "Male", F = "Female";
	int N;
	cin >> N;

	string f0, f1;
	cout << 0 << endl;
	cin >> f0;
	if (f0 == V) { return 0; }
	cout << N - 1 << endl;
	cin >> f1;
	if (f1 == V) { return 0; }

	int l = 0, r = N - 1;
	string s;
	int cnt = 0;
	while (r - l > 1 && cnt++ < 19) {
		int m = (r + l) / 2;

		cout << m << endl;
		cin >> s;
		if (s == V) { return 0; }
		if (s == f0) {
			if (m % 2 == 0) { l = m; }
			else { r = m; }
		} else {
			if (m % 2 == 0) { r = m; }
			else { l = m; }
		}
	}

	return 0;
}
