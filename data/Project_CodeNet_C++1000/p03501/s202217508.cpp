#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int n, a, b;
	cin >> n >> a >> b;
	printf("%d\n", (a * n > b) ? b : (a * n));
	return 0;
}
