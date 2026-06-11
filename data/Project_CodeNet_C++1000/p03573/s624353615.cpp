#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> a(3);
	for (int i = 0; i < 3; i++)
		cin >> a.at(i);
	if (a.at(0) != a.at(1))
		cout << (a.at(0) == a.at(2) ? a.at(1) : a.at(0)) << endl;
	else
		cout << a.at(2) << endl;
}