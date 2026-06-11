#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;

	const int p = 26;
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		vector<int> alphaNumL(p, 0);
		vector<int> alphaNumR(p, 0);

		for (int j = 0; j < i; j++) {
			alphaNumL[(int)(s[j] - 'a')] = 1;
		}
		for (int j = i; j < n; j++) {
			alphaNumR[(int)(s[j] - 'a')] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < p; j++) {
			if (alphaNumL[j] == 1 && alphaNumR[j] == 1) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << endl;
	return 0;
}