#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string S;
	cin >> S;
	int len = S.length(), fav = 753, ans = INT_MAX;
	for (int i = 0; i <= len - 3; ++i) {
		string b = S.substr(i, 3);
		int best = stoi(b);
		ans = min(ans, abs(best - fav));
	}
	cout << ans << '\n';	
	
	return 0;
}
