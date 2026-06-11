#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b, c;
	char	tmp;
	cin >> a >> tmp >> b >> tmp >> c;
	if (b == 4)
		cout << (c <= 30 ? "Heisei" : "TBD") << endl;
	else
		cout << (b < 4 ? "Heisei" : "TBD") << endl;
}