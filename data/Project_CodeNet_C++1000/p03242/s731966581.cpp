#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	for (int i = 0; i < 3; i++)
	{
		char	a;
		cin >> a;
		cout << (a == '1' ? 9 : 1);
	}
	cout << endl;
}