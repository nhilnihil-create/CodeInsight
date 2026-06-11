#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[200];
	cin >> n;
	int c = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool ok = true;
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2)
			{
				ok = false;
				break;
			}
			else
			{
				a[i] /= 2;
			}
		}
		if (!ok)
			break;
		else
			c++;
	}
	cout << c << endl;
}
