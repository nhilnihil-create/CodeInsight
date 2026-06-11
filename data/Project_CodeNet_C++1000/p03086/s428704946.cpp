#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;
		for (int j = i; j < s.size(); j++) {
			if (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T') cnt++;
			else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}