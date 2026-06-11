#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int>west(n + 1, 0), east(n + 1, 0);
	for (int i = 0; i < n; i++) {
		west[i + 1] += west[i] + (s[i] == 'W' ? 1 : 0);
		east[i + 1] += east[i] + (s[i] == 'E' ? 1 : 0);
	}

	int ans = 1e10;
	for (int i = 0; i <=n; i++) {
		ans = min(ans, west[i] + east[n] - east[i]);
	}
	cout << ans << endl;

	return 0;
}