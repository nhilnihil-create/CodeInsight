#include <bits/stdc++.h>
using namespace std;

long long sum, tmp;
unsigned long long ans;
int i, j, n;
int a[200100];

int main() {
	cin >> n;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
		while (j + 1 <= n && (tmp ^ a[j + 1]) == sum + a[j + 1]) {
			tmp ^= a[j + 1];
			sum += a[j + 1];
			j++;
		}
		if (tmp == sum) {
			ans += j - i + 1;
		}
		tmp ^= a[i];
		sum -= a[i];
	}
	printf("%lld\n", ans);
	return 0;
}