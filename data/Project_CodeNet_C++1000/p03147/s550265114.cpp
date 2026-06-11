#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007
#define SEP " "

int		main(void)
{
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	vector<int> f(n);
	int c = 0;
	while (true)
	{
		int tmp = -1;
		int i = 0;
		while (i < n)
		{
			if (f[i] < h[i])
			{
				tmp = f[i++]++;
				break ;
			}
			i++;
		}
		if (tmp == -1)
			break ;
		while (i < n && f[i] == tmp && f[i] < h[i])
		{
			f[i++]++;
		}
		c++;
	}
	cout << c << endl;
}
