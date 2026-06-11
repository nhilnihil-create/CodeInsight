#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		a, b;
	cin >> a >> b;
	cout << (a * b % 2 == 0 ? "No" : "Yes")  << endl;
}