#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010];

int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector <int> t1;
	int ans = 0; long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (a[i] > b[i]) t1.push_back(a[i] - b[i]);
		else if (a[i] < b[i]) sum += b[i] - a[i], ans++;
	}
	sort(t1.rbegin(), t1.rend());
	int now = 0;
	while (now < t1.size() && sum > 0) {
		ans++, sum -= t1[now++];
	}
	if (sum > 0) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
