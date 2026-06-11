#include <bits/stdc++.h>

using namespace std;

int a[200002], b[200002];

long long ans = 0;
long long t = 1;

int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i <= 29; i++) {
		vector <long long> c;
		vector <long long> d;
		for (int j = 1; j <= n; j++) {
			c.push_back(b[j] % (2 * t));
			d.push_back(a[j] % (2 * t));
		}
		sort(c.begin(), c.end());
		long long aux = 0;
		for (int j = 0; j < n; j++) {
			aux += lower_bound(c.begin(), c.end(), 2 * t - d[j]) - c.begin();
			aux -= lower_bound(c.begin(), c.end(), 1 * t - d[j]) - c.begin();
			aux += lower_bound(c.begin(), c.end(), 4 * t - d[j]) - c.begin();
			aux -= lower_bound(c.begin(), c.end(), 3 * t - d[j]) - c.begin();
		}
		ans += t * (aux % 2);
		t = t * 2;
	}
	cout << ans << endl;
	return 0;
}
