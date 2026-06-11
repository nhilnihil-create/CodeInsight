#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int a[3] = {};
	for (auto it = begin(s); it != end(s); it++) {
		if (*it == 'a') {
			a[0]++;
		} else if (*it == 'b') {
			a[1]++;
		} else {
			a[2]++;
		}
	}
	sort(a, a + 3);
	cout << (a[2] - a[0] <= 1 ? "YES" : "NO") << endl;
	return 0;
}
