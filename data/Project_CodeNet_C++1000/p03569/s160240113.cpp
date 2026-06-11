//CODE FESTIVAL 2017 qual C
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(ll argc, char* argv[]) {
	string s;
	cin >> s;
	string excludeX;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]!='x')
		{
			excludeX += s[i];
		}
	}
	for (int i = 0; i < excludeX.size()/2; i++)
	{
		if (excludeX[i]!=excludeX[excludeX.size()-i-1])
		{
			cout << -1 << endl;
			return 0;
		}
	}
	ll leftSide = 0;
	ll rightSide = s.size()-1;
	ll answer = 0;
	while (leftSide<rightSide)
	{
		if (s[leftSide]==s[rightSide])
		{
			leftSide++;
			rightSide--;
		}
		else
		{
			answer++;
			if (s[leftSide] == 'x')
			{
				leftSide++;
			}
			else
			{
				rightSide--;
			}
		}
	}


	cout << answer << endl;
	return 0;
}