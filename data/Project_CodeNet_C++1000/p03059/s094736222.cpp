#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, t;
	scanf("%d%d%d", &a, &b, &t);
	int p = a;
	int count = 0;
	while (t - p >= 0) {
		p += a;
		count += b;
	}
	printf("%d\n", count);
	return 0;
}