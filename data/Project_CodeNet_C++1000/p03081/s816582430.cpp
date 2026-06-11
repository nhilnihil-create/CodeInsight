#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<char> ts(q), ds(q);
	for (int i = 0; i < q; i++)
	{
		cin >> ts[i] >> ds[i];
	}

	int ans = n;

	{
		int l = -1, r = n;
		while (1 < r - l)
		{
			int mid = (l + r) / 2;

			bool f = false;
			int pos = mid;

			for (int i = 0; i < q; i++)
			{
				if (s[pos] == ts[i])
				{
					if (ds[i] == 'L')
					{
						pos--;
						if (pos < 0)
						{
							f = true;
							break;
						}
					}
					else
					{
						pos++;
						if (n <= pos)
						{
							break;
						}
					}
				}
			}

			(f ? l : r) = mid;
		}
		ans -= l + 1;
	}

	{
		int l = -1, r = n;
		while (1 < r - l)
		{
			int mid = (l + r) / 2;

			bool f = false;
			int pos = mid;

			for (int i = 0; i < q; i++)
			{
				if (s[pos] == ts[i])
				{
					if (ds[i] == 'L')
					{
						pos--;
						if (pos < 0)
						{
							break;
						}
					}
					else
					{
						pos++;
						if (n <= pos)
						{
							f = true;
							break;
						}
					}
				}
			}

			(f ? r : l) = mid;
		}

		ans -= n - r;
	}

	cout << ans << endl;

	return 0;
}