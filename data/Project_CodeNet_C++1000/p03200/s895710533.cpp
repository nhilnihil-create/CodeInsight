#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	string S; cin >> S;
	long long white = 0;
	vector<long long>pos;
	rep(i, S.size()) {
		if (S.at(i) == 'W') {
			white++;
			pos.push_back(i);
		}
	}
	long long ans = 0;
	rep(i, white) {
		ans += pos.at(i) - i;
	}
	cout << ans << endl;
}
