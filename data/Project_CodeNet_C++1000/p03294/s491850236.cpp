#include <bits/stdc++.h>

using namespace std;

int n, ta;
long long ans;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &ta);
		ans += ta - 1;
	}
	printf("%lld\n", ans);
	return 0;
}

