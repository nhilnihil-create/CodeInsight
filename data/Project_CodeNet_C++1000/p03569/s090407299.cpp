// In the name of God

#include <bits/stdc++.h>

using namespace std;

bool f;
string s;

int solve(int l, int r) {
	if(l>=r) return 0;
	if(s[l] == s[r]) {
		return solve(l+1, r-1);
	}
	if(s[l] == 'x') return solve(l+1, r) + 1;
	if(s[r] == 'x') return solve(l, r-1) + 1;
	f = true;
	return 1e9;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int ans = solve(0, (int)s.length() - 1);	
	if(f) cout << -1;
	else cout << ans;

	return 0;
}
