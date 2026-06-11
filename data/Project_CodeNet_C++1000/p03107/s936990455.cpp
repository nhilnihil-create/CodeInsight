
// C - Unification

// スタックを用いた解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int ans = 0;

	stack<char> stk;

	for (int i=0; i<S.size(); i++) {
		char c = S[i];

		if (stk.empty()) {
			stk.push(c);
			continue;
		}

		if (c == '0') {
			if (stk.top() == '1') {
				stk.pop();
				ans += 2;
			} else {
				stk.push(c);
			}
		}

		if (c == '1') {
			if (stk.top() == '0') {
				stk.pop();
				ans += 2;
			} else {
				stk.push(c);
			}
		}
	}

	cout << ans << endl;

	return 0;
}