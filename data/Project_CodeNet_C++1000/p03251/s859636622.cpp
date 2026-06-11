#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int		main(void)
{
	int n, m, x, y;

	scanf("%d%d%d%d", &n, &m, &x, &y);
	string ans = "No War";
	set<int> a;
	set<int> b;

	a.insert(x);
	for (int i = 0; i < n; i++)
	{
		int tmp;

		cin >> tmp;
		a.insert(tmp);
	}
	b.insert(y);
	for (int i = 0; i < m; i++)
	{
		int tmp;

		cin >> tmp;
		b.insert(tmp);
	}
	if (*rbegin(a) >= *begin(b))
		ans = "War";	
	cout << ans << endl;
}

