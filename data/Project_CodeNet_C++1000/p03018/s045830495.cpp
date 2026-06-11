#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	string S,S_;
	cin >> S_;
	if (S_.size() < 3) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < S_.size() - 1; i++) {
		if (S_[i] == 'B' && S_[i + 1] == 'C') {
			S.push_back('D');
			i++;
		}
		else {
			S.push_back(S_[i]);
		}
	}

	vector<string> s;
	string tmp = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A' || S[i] == 'D')tmp += S[i];
		else {
			if (tmp == "")continue;
			s.push_back(tmp);
			tmp = "";
		}
	}
	if (tmp != "")s.push_back(tmp);

	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (s[i][j] == 'A')cnt++;
			else ans += cnt;
		}
	}
	cout << ans << endl;
}