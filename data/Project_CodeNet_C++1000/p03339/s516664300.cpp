#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	vector<int> accumW(n + 1, 0);
	vector<int> accumE(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		accumW[i] += accumW[i - 1];
		accumE[i] += accumE[i - 1];
		if (s[i - 1] == 'W') accumW[i] += 1;
		if (s[i - 1] == 'E') accumE[i] += 1;
	}
	int ans = 2147483647;
	for (int i = 1; i <= s.size(); i++) {
		int tmp = 0;
		tmp += accumW[i - 1];
		tmp += accumE[n] - accumE[i];
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}