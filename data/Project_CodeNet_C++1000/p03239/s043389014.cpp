#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.141592653589793238

int main() {
	int N, T;
	cin >> N >> T;
	int ans = -1;
	rep(i, N) {
		int c, t;
		cin >> c >> t;
		if (t <= T) {
			if (ans == -1) {
				ans = c;
			}
			else if (c < ans) {
				ans = c;
			}
		}
	}
	if (ans == -1) {
		puts("TLE");
	}
	else {
		cout << ans << endl;
	}
	return 0;
}