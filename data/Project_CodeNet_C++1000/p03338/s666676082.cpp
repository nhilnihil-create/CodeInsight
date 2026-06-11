#include <bits/stdc++.h>
using namespace std;

int cntcommonchar(string s1, string s2) {
	set<char> c1, c2, r;
	for (int i = 0; i < s1.size(); i++) {
		c1.insert(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++) {
		c2.insert(s2[i]);
	}
	set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), inserter(r, r.end()));
	return r.size();
}

int main() {
	int N;
	string S;
	cin >> N >> S;
	int ans = INT_MIN;
	for (int i = 1; i < N; i++) {
		ans = max(ans, cntcommonchar(S.substr(0, i), S.substr(i, N - i)));
	}
	cout << ans << endl;
	return 0;
}
