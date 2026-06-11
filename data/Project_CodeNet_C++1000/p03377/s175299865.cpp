#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b, x;
	cin >> a >> b >> x;
	int		tmp = 0;
	bool	flag = false;
	tmp += a;
	if (tmp != x)
	{
		for (size_t i = 0; i <= b; i++)
		{
			tmp++;
			if (tmp == x)
				flag = true;
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	else
		cout << "YES" << endl;
}