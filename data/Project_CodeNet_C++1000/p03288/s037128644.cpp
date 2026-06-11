#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a;
	cin >> a;
	if (a >= 2800)
		cout << "AGC" << endl;
	else
		cout << (a >= 1200 ? "ARC" : "ABC") << endl;
}