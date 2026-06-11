#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b;
	cin >> a >> b;
	cout << (b % a ? b - a : a + b) << endl;
}