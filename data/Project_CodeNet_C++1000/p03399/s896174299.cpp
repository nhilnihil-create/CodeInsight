#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	priority_queue<int, vector<int>, greater<int>> train;
	priority_queue<int, vector<int>, greater<int>> bus;
	vector<int> tmp(4);
	for (int i = 0; i < 4; i++)
		cin >> tmp.at(i);
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			train.push(tmp.at(i));
		else
			bus.push(tmp.at(i));
	}
	cout << train.top() + bus.top() << endl;

}