#include <bits/stdc++.h>
using namespace std;

int main() {
	string S, k = "keyence";
	cin >> S;
	int N = S.size(), n = k.size();
	for (int i = 0; i <= k.size(); i++) {
		if (S.substr(0, i) + S.substr(N - n + i, n - i) == k) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
