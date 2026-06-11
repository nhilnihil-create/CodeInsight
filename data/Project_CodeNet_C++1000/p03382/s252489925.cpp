#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int mx = *max_element(a.begin(), a.end());
	int k = mx / 2;
	int r, dist = 2e9;
	for (int i = 0; i < n; ++i)
		if (a[i] != mx && dist > abs(a[i] - k))
			dist = abs(a[i] - k), r = a[i];
	printf("%d %d\n", mx, r);
  return 0;
}