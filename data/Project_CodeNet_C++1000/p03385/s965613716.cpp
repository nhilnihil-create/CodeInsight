#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	string	abc;
	cin >> abc;
	sort(abc.begin(), abc.end());
	cout << (abc == "abc" ? "Yes" : "No") << endl;
}