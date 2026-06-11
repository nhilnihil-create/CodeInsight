#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	int ans = 1e9;
	for (int n = 0;n<N;++n) {
		int c, t;
		cin >> c >> t;
		if (t<=T) {
			ans = min(ans, c);
		}
	}
	if (1e9 == ans) {
		cout << "TLE" << endl;
	}
	else {
		cout << ans << endl;
	}
	
	return 0;
}