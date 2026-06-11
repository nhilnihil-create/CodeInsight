#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>up(n), mid(n), low(n);
	for (int& i : up) cin >> i;
	for (int& i : mid) cin >> i;
	for (int& i : low) cin >> i;
	sort(up.begin(), up.end());
	sort(low.begin(), low.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x = lower_bound(up.begin(), up.end(), mid[i]) - up.begin();
		int y = upper_bound(low.begin(), low.end(), mid[i]) - low.begin();
		y = (n - 1) - y + 1;
		ans += (1LL * x * y);
		//int x = lower_bound(up.begin(), up.end(), up[i]);
	}
	cout << ans;
		return 0;
}

