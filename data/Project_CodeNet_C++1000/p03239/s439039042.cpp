#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int n, T;

int t[105], c[105];

int main() {

	FAST;

	cin >> n >> T;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i] >> t[i];
	}	
	int ans = 1005;
	for (int i = 1; i <= n; i ++) {
		if (t[i] <= T) {
			ans = min(ans, c[i]);
		}
	}
	if (ans == 1005) {
		cout << "TLE\n";
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}