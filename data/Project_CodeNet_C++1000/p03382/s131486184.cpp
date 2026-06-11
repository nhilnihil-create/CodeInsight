#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int a[MAXN];

int n, w1, w2;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[n] % 2 == 0)
		w1 = a[n] / 2, w2 = w1 + 1;
	else
		w1 = w2 = (a[n] + 1) / 2;
	int x = lower_bound(a + 1, a + n, w2) - a, y = x - 1;
	if (x == n)
		cout << a[n] << " " << a[y] << endl;
	else if (y == 0)
		cout << a[n] << " " << a[x] << endl;
	else
	{
		if (w1 - a[y] <= a[x] - w2)
			cout << a[n] << " " << a[y] << endl;
		else
			cout << a[n] << " " << a[x] << endl;
	}
	return 0;
}
