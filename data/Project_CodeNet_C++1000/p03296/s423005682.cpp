#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> v;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) count++;
		else {
			v.push_back(count);
			count = 1;
		}
	}
	v.push_back(count);
	int ans = 0;
	for (const auto& item : v) ans += item / 2;
	cout << ans << endl;
}
