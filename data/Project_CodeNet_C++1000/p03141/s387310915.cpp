#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<long long, long long>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first += a[i].second;
	}

	sort(a.rbegin(), a.rend());
	
	long long ans = 0;
	for (int i = 0; i < n; i+=2) {
		ans += a[i].first;
	}

	for (int i = 0; i < n; i++) {
		ans -= a[i].second;
	}
	cout << ans << endl;

	return 0;
}