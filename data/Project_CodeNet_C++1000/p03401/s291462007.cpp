#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int sum = 0;
	for (int i = 1; i < a.size(); i++) sum += abs(a[i] - a[i - 1]);

	vector<int> diff(n + 2);
	for (int i = 1; i <= n; i++) {
		diff[i] = abs(a[i + 1] - a[i - 1]) - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1]);
	}

	for (int i = 1; i <= n; i++) cout << sum + diff[i] << endl;
}
