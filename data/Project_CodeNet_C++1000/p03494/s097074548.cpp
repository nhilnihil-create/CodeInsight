#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	int count = 0;
	bool change = true;
	while (change)
	{
		rep(i, n)
		{
			if (a[i] % 2 != 0)
				change = false;
		}
		if (change)
		{
			count++;
			rep(i, n) a[i] /= 2;
		}
	}
	printf("%d\n", count);
	return 0;
}