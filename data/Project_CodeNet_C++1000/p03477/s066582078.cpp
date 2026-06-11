#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b != c + d)
		cout << (a + b > c + d ? "Left" : "Right") << endl;
	else
		cout << "Balanced" << endl;
}