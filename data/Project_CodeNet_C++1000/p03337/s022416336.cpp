#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a;
	int		b;
	int		add;
	int		sub;
	int		mul;
	cin >> a;
	cin >> b;
	add = a + b;
	sub = a - b;
	mul = a * b;
	cout << max(add, max(sub, mul)) << endl;
}