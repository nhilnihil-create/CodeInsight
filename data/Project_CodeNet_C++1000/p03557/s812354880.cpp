#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int a[110000];
int b[110000];
int c[110000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (lower_bound(a, a + n, b[i]) - a) * (n - (upper_bound(c, c + n, b[i]) - c));
	cout << ans << endl;
}