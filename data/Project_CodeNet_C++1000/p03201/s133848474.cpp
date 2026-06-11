#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map <int, int> cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	sort (a.begin(), a.end());
	int ans = 0;
	for (int i=n-1; i>=0; i--) {
		if (!cnt[a[i]]) continue;
		cnt[a[i]] --;
		int step = 1<<((int)log2(a[i]) + 1);
		int req = step - a[i];
		if (cnt[req]) {
			ans ++;
			cnt[req] --;
		}
	}
	cout << ans;
	return 0;
}