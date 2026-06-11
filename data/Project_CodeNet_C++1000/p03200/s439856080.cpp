#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	long long ans = 0, cntb = 0;
	for (long long i = 0; i < S.size(); i++) {
		if (S[i] == 'B') {
			cntb++;
		} else if (S[i] == 'W') {
			ans += cntb;
		}
	}
	cout << ans << endl;
	return 0;
}
