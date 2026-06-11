
// C - Inserting 'x'

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	string t = "";
	for (int i=0; i<s.size(); i++) {
		if (s[i] != 'x') t.push_back(s[i]);
	}
	auto rev_t = t;
	reverse(rev_t.begin(), rev_t.end());
	if (t != rev_t) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> cnt;

	int c = 0;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == 'x') c++;
		else {
			cnt.push_back(c);
			c = 0;
		}
	}
	cnt.push_back(c);

	auto rev_cnt = cnt;
	reverse(rev_cnt.begin(), rev_cnt.end());

	int ans = 0;
	for (int i=0; i<cnt.size(); i++) {
		ans += abs(cnt[i] - rev_cnt[i]);
	}
	ans /= 2;

	cout << ans << endl;

	return 0;
}