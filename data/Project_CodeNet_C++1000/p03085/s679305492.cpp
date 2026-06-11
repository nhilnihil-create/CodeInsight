#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	char	a;
	cin >> a;
	if (a == 'A' || a == 'T')
		cout << (a == 'A' ? "T" : "A") << endl;
	else
		cout << (a == 'C' ? "G" : "C") << endl;
}