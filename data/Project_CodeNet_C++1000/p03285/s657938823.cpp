#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;

	rep1(i, n/7)
	{
		rep1(j, n / 4)
		{
			if (i*7 + j*4 == n)
			{
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}