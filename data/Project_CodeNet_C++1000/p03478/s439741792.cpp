#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int t, c;
		t = i; c = 0;
		while (t > 0) {
			c += t % 10;
			t /= 10;
		}
		if(c >= a && c <= b) sum += i;
	}
	printf("%d\n", sum);
	return 0;
}