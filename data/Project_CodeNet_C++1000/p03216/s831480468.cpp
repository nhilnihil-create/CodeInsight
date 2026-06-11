#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, q;
	string s;
	cin >> n >> s >> q;
	for (int t = 0; t < q; t++)
	{
		int k;
		cin >> k;
		//output k-DMC
		int64_t d = 0, m = 0, dm = 0, dmc = 0;
		for (int i = 0, j = 0; j < n;)
		{
			while (k <= j - i)
			{
				if (s[i] == 'D')
				{
					d--;
					dm -= m;
				}
				if (s[i] == 'M')
				{
					m--;
				}
				i++;
			}
			while (j < n && j - i < k)
			{
				if (s[j] == 'D')
				{
					d++;
				}
				if (s[j] == 'M')
				{
					m++;
					dm += d;
				}
				if (s[j] == 'C')
				{
					dmc += dm;
				}
				j++;
			}
		}
		cout << dmc << endl;
	}
	return 0;
}