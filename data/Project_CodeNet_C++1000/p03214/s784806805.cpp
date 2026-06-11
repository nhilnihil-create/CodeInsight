#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a >= b) { a = b; return true; } return false; }

int main() {
	
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int tmp = 2147483647;
	int ans;
	for (int i = n - 1; i >= 0; i--) {
		if (chmin(tmp, abs(n * a[i] - sum))) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}