#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool actg(string s) {
	for (auto& e:s) {
		if (e == 'A' || e == 'T' || e == 'C' || e == 'G') continue;
		return false;
	}
	return true;
}
int main() {
	int n, ans = 0;
	string s;
	cin >> s;
	n=s.size();
	for (int i=0; i<n; i++) {
		for (int j=1; j<=n-i; j++) {
			string subs = s.substr(i,j);
			// cout << subs << '\n';
			if(actg(subs)) ans = max(ans, (int)subs.size());
		}
	}
	return cout << ans, 0;
}
