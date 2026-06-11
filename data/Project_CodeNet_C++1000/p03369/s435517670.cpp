#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
    string	a;
	cin >> a;
	int		cnt;
	cnt = 0;
	for (auto &i : a)
	{
		if (i == 'o')
			cnt++;
	}
	cout << 700 + (cnt * 100) << endl;
}