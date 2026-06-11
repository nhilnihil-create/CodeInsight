#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> a(3);
	int		d;
	for (int i = 0; i < 3; i++)
		cin >> a.at(i);
	cin >> d;
	if (abs(a.at(0) - a.at(2)) <= d)
		cout << "Yes" << endl;
	else
		cout << (abs(a.at(0) - a.at(1)) <= d && abs(a.at(1) - a.at(2)) <= d ? "Yes" : "No") << endl;
}