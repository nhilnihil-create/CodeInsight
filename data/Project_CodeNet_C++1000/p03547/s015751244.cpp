#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	char	a;	cin >> a;
	char	b;	cin >> b;
	if (a != b)
		cout << (a > b ? ">" : "<") << endl;
	else
		cout << "=" << endl;
}