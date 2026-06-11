#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a;
	int		b;
	cin >> a >> b;
	cout << (b < a ? a - 1 : a) << endl;
}