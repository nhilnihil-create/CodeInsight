#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{

	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}
	a.at(n) = 0;
	int i = 1;
	int count = 0;
	while (i < n)
	{
		if (a.at(i - 1) == a.at(i))
		{
			count++;
			a.at(i) += a.at(i - 1)+a.at(i+1);
			i++;
		}
		else
			i++;
	}
	cout << count << endl;
}
