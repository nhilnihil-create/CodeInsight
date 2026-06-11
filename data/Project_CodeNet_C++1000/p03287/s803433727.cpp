#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	long long n, m;
	cin >> n >> m;
	long long s[n];
	map<long long, long long> ma;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (i == 0)
			s[i] = a;
		else
			s[i] = s[i-1] + a;
		ma[s[i]%m]++;
	}
	long long ans = 0;
	for (auto e : ma) {
		if (e.first == 0)
			ans += e.second;
		if (e.second >= 2) {
			ans += e.second * (e.second-1)/2;
		}
	}
	cout << ans << endl;

	return 0;
}