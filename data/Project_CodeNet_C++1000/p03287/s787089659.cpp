#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	map<int, int> mp;
	mp[0] = 1;
	long long ans = 0;
	int sum = 0;
	rep(i,n) {
		(sum += a[i]) %= m;
		ans += mp[sum] ++ ;
	}
	cout << ans << endl;
}
