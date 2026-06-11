#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int a, b, c;

	cin >> a >> b >> c;
	if (a == b)
		cout << c;
	else if (a == c)
		cout << b;
	else
		cout << a;
	cout << endl;
}

