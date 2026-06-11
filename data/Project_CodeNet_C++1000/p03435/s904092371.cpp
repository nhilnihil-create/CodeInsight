#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;

	int l, r;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c;

		if (!i)
		{
			l = abs(a - b);
			r = abs(b - c);
		}
		if (l != abs(a - b) || r != abs(b - c))
		{
			cout << "No" << endl;
			return (0);
		}
	}
	cout << "Yes" << endl;
	return (0);
}
