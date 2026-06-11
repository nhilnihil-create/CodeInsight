#include <bits/stdc++.h>

using namespace std;

pair<int, int> x[222222];
int a[222222];
int main() {
	a[0] = 1;
	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &x[i].first, &x[i].second);
	sort(x, x + n);
	for (int i = 1; i <= w; i++) {
		for (a[i] = a[i - 1] + 1; a[i] <= h && !binary_search(x, x + n, make_pair(a[i], i)); a[i]++)
			if (!binary_search(x, x + n, make_pair(a[i], i + 1)))
				goto p;
		while (i < w) a[++i] = h + 1;
		break;
	p:;
	}
	int m = h + 1;
	for (int i = 0; i < n; i++)
		if (x[i].first >= a[x[i].second])
			m = min(m, x[i].first);
	cout << m - 1 << endl;
	return 0;
}
