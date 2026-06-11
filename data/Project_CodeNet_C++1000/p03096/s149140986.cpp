#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 300100;
const int MOD = (int) 1e9 + 7;

int n, a[N], f[N], d[N];

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[a[i]] = 0;
	}

	d[0] = 1;

	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1];
		if (i == 0 || a[i] != a[i - 1]) {
			d[i] += f[a[i]];
			d[i] %= MOD;
			f[a[i]] += d[i - 1];
			f[a[i]] %= MOD;
		}
	}

	printf("%d\n", d[n]);

	return 0;

}