#include <bits/stdc++.h>
using namespace std;

int main() {
	int k; cin >> k;
	int64_t a[k]; for(int i = 0; i < k; ++i) cin >> a[i];
	int64_t l, r;
	{
		int64_t ok = 0, ng = 1e18;
		while(abs(ok - ng) > 1) {
			int64_t mid = (ok + ng) / 2;
			int64_t n = mid;
			for(int i = 0; i < k; ++i) {
				n = (n / a[i]) * a[i];
			}
			if(n < 2) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		l = ng;
	}
	{
		int64_t ok = 0, ng = 1e18;
		while(abs(ok - ng) > 1) {
			int64_t mid = (ok + ng) / 2;
			int64_t n = mid;
			for(int i = 0; i < k; ++i) {
				n = (n / a[i]) * a[i];
			}
			if(n <= 2) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		r = ok;
	}
	if(l > r) {
		cout << -1 << '\n';
	} else {
		cout << l << " " << r << '\n';
	}
	return 0;
}