#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char c;
	int y = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'Y')
		{
			y = 1;
			break;
		}
	}
	if (y)
		cout << "Four" << endl;
	else
		cout << "Three" << endl;
}
