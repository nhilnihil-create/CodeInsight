#include <bits/stdc++.h>

using namespace std;

const int N = 2000000;

int n;
long long res;
long long a[N + 1];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	if(a[1]) { puts("-1"); return 0; }
	for(int i = 2; i <= n; i++)
		if(a[i] > a[i - 1] + 1)
			{ puts("-1"); return 0; }
	for(int i = n; i >= 1; i--)
		if(a[i] >= a[i + 1])
			res += a[i];
	printf("%lld\n", res);
	return 0;
}