#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans = 1e9;
	for (int n = 0;n<S.size()-2;++n) {
		int num = (S[n] - '0') * 100 + (S[n+1] - '0') * 10 + (S[n+2] - '0');
		ans = min(ans, abs(753-num));
	}
	cout << ans <<endl;
}