#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	long long suma = 0, sumb = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		suma += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sumb += b[i];
	}

	if (sumb > suma) {
		cout << -1 << endl;
		return 0;
	}

	vector<long long> diff;
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[i]) {
			diff.emplace_back(a[i] - b[i]);
		}
	}
	sort(diff.rbegin(), diff.rend());
	for (int i = 1; i < diff.size(); i++) {
		diff[i] += diff[i - 1];
	}

	int ans = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			sum += b[i] - a[i];
			ans++;
		}
	}
	if (sum != 0) {
		for (int i = 0; i < diff.size(); i++) {
			if (sum <= diff[i]) {
				ans += i + 1;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}