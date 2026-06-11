#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	string S, T;
	cin >> S >> T;

	string ans = "No";
	for (int i = 0; i < S.size(); ++i) {
		string S2 = S[S.size() - 1] + S;
		S = S2.substr(0, S.size());

		if (S == T) {
			ans = "Yes";
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
