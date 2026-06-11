#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	vector<int> A(5);
	int		k;
	for (int i = 0; i < 5; i++)
		cin >> A.at(i);
	cin >> k;
	sort(A.begin(), A.end());
	cout << (A.at(4) - A.at(0) <= k ? "Yay!" : ":(") << endl;
}