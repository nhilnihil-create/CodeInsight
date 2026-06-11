#include <bits/stdc++.h>
using namespace std;

int n, k, q;
int a[2020];
int ans = 1e9;

void f(int idx) {
	vector<int> v;
	vector<int> num;
	for(int i = 0; i <= n; ++i) {
		if(a[i] < a[idx]) {
			int vn = v.size();
			if(vn >= k) {
				sort(v.begin(), v.end());
				for(int j = 0; j <= vn - k; ++j) {
					num.push_back(v[j]);
				}
			}
			v.clear();
		} else {
			v.push_back(a[i]);
		}
	}
	if(num.size() < q) return;
	sort(num.begin(), num.end());
	ans = min(ans, num[q - 1] - num[0]);
}

int main() {
	cin >> n >> k >> q;
	for(int i = 0; i < n; ++i) cin >> a[i];
	a[n] = -1;
	for(int i = 0; i < n; ++i) {
		f(i);
	}
	cout << ans << '\n';
	return 0;
}