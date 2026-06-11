#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = abs(a[0]);
	for (int i = 0; i < n - 1; i++) sum += abs(a[i + 1] - a[i]);
	sum += abs(0 - a[n - 1]);

	vector<int> diff(n);
	diff[0] = abs(a[1]) - abs(a[1] - a[0]) - abs(a[0]);
	diff[n - 1] = abs(0 - a[n - 2]) - abs(a[n - 1] - a[n - 2]) - abs(0 - a[n - 1]);
	for (int i = 1; i <= n - 2; i++) {
		diff[i] = abs(a[i + 1] - a[i - 1]) - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1]);
	}

	for (int i = 0; i < n; i++) cout << sum + diff[i] << endl;
}
