#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	vector<bool>include_X(26, false), include_Y(26, false);
	int ans = -1;
	for (int i = 0; i < N; i++) {
		string X = S.substr(0, i), Y = S.substr(i, N - i);
		fill(include_X.begin(), include_X.end(), false);
		fill(include_Y.begin(), include_Y.end(), false);
		for (int j = 0; j < X.size(); j++) {
			include_X.at(X.at(j) - 97) = true;
		}
		for (int j = 0; j < Y.size(); j++) {
			include_Y.at(Y.at(j) - 97) = true;
		}
		int cap = 0;
		for (int j = 0; j < 26; j++) {
			if (include_X.at(j) && include_Y.at(j)) cap++;
		}
		if (ans < cap) ans = cap;
	}
	cout << ans << endl;
}
