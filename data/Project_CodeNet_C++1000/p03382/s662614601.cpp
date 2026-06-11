#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0, x; i < n; i++) scanf("%d", &x), a.push_back(x);
	sort(a.begin(), a.end());
	int ans = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] * 2 > a[n - 1])
		{
			if (ans < a[n - 1] - a[i]) ans = a[i];
		}
		else ans = max(ans, a[i]);
	}
	return !printf("%d %d", a[n - 1], ans);
}