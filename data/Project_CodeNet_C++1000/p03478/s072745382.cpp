#include "bits/stdc++.h"

using namespace std;

int main() {
	int N,A,B;
	cin >> N>>A>>B;
	int ans = 0;
	for (int i = 1;i<=N;++i) {
		int ntemp = i;
		int memo = 0;
		while (0 != ntemp) {
			memo += ntemp % 10;
			ntemp /= 10;
		}
		if ((memo <= B) && (memo >=A)) {
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
