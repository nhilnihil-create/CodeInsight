#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int r, d, x;
	scanf("%d%d%d", &r, &d, &x);
	rep(i, 10) {
		printf("%d\n", r * x - d);
		x = r * x - d;
	}
	return 0;
}