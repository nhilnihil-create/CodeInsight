#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 20;
int n, a[maxn], g;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i+1])
		{
			if (a[i+1] == a[i+2])
			{
				i += 1;
				g++;
			}
			else
			{
				g++;
			}
		}
	}
	cout << g;
	return 0;
}
