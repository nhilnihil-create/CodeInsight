#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	vector<int> H(n);
	for (int i = 0; i < n; ++i)
		cin >> H[i];

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		while (H[i] > 0)
		{
			for (int j = i; j < n; ++j)
			{
				if (H[j] > 0)
					--H[j];
				else
					break ;
			}
			++ans;
		}
	}
	cout << ans << endl;
}

