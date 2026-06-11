#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, ans = 0;
	cin >> n;
	if (n >= 105) {
		for (int i = 105; i <= n; i += 2) {
			int count = 0;
			for (int j = 1; j*j <= i; j++) {
				if (j*j == i) count++;
				else if (i % j == 0) count += 2;
			}
			if (count == 8) ans++;
		}
	}
	cout << ans;
	return 0;
}
