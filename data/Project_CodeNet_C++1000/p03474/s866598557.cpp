#include <bits/stdc++.h>
using namespace std;

int num = 0;

bool checking_the_format(int a, int i)
{
	num++;
	if (num == a + 1)
	{
		if (!(i == '-'))
		{
			return false;
		}
	}
	else if (!(isdigit(i)))
	{
		return false;
	}
	return true;
}

int main()
{
	int a, b;
	string s;
	cin >> a >> b >> s;
	for (int i : s)
	{
		if (checking_the_format(a, i) == false)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}