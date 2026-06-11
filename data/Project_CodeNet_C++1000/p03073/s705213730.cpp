#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S;
	cin >> S;

	int ans = 0;
	int tmp = 0;
	for (int i = 0; i < S.size(); ++i) {
		if (i % 2 == 0) {
			if (S[i] == '0') {
				tmp++;
			}
		}
		else {
			if (S[i] == '1') {
				tmp++;
			}
		}
	}
	ans = tmp;
	tmp = 0;
	for (int i = 0; i < S.size(); ++i) {
		if (i % 2 == 0) {
			if (S[i] == '1') {
				tmp++;
			}
		}
		else {
			if (S[i] == '0') {
				tmp++;
			}
		}
	}
	ans = min(ans, tmp);

	cout << ans << endl;
	return 0;
}
