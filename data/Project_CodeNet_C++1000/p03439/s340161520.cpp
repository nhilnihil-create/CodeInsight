#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
int sex[100000];
bool check(int l, int r) {
	int len = r - l + 1;
	if (len % 2) {
		return sex[l] != sex[r];
	} else {
		return sex[l] == sex[r];
	}
}
int main() {
	int N;
	cin >> N;
	string ans;
	cout << 0 << endl;
	cin >> ans;
	if (ans == "Vacant") {
		return 0;
	} else if (ans == "Male") {
		sex[0] = 1;
	}
	cout << N - 1 << endl;
	cin >> ans;
	if (ans == "Vacant") {
		return 0;
	} else if (ans == "Male") {
		sex[N - 1] = 1;
	}
	int l = 0, r = N - 1;
	while (r - l >= 4) {
		int m = (l + r) / 2;
		cout << m << endl;
		cin >> ans;
		if (ans == "Vacant") {
			return 0;
		} else if (ans == "Male") {
			sex[m] = 1;
		}
		int len = r - l + 1;
		sex[m - 1] = sex[m + 1] = !sex[m];
		if (check(l, m - 1)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	for (int i = l; i <= r; i++) {
		cout << i << endl;
		cin >> ans;
		if (ans == "Vacant") return 0;
	}
}