#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a.rbegin(), a.rend());

	int cx = 0, cy = 0, ch = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			int h = a[0].first + abs(i - a[0].second.first) + abs(j - a[0].second.second);
			bool ok = true;

			for (int k = 1; k < n; k++) {
				if (a[k].first != max(h - abs(i - a[k].second.first) - abs(j - a[k].second.second), 0)) {
					ok = false;
					break;
				}
			}
			
			if (ok) {
				if (ch < h) {
					cx = i;
					cy = j;
					ch = h;
				}
			}
		}
	}
	printf("%d %d %d\n", cx, cy, ch);

	return 0;
}