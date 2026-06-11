#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int a;
	cin >> a;
	string S = "Christmas";
	for (int i = a; i < 25; i++)
		S += " Eve";
	cout << S << endl;
}