#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {
	int n , k;
	cin >> k >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
		if (k >= n) {
		cout << 0;
		return 0;
	}
	sort(v.begin(),v.end());
	vector<int> ans(n - 1);
	for (int i = 1; i < n; ++i) {
		ans[i - 1] = v[i] - v[i - 1];
	}
	sort(ans.begin(),ans.end());
	ll res = 0;
	for (int i = 0; i < n - k; ++i) {
		res += 1LL * ans[i];
	}
	cout << res;
}

