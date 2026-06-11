#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	string	a;	cin >> a;
	string	b;	cin >> b;
	int		j = 0;
	for (int i = 3 - 1; i >= 0; i--)
	{
		if (a.at(j) != b.at(i))
		{
			cout << "NO" << endl;
			goto OUT;
		}
		j++;
	}
	OUT:
	if (j == 3)
		cout << "YES" << endl;
}