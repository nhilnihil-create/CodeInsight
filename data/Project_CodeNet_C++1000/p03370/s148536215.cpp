#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
string yes = "Yes\n";
string no = "No\n";

int  main()
{
	int n, x; cin >> n >> x;

	int sum = 0;
	vector<int> m(n);
	rep(i, n)
	{
		cin >> m[i];
		sum += m[i];
	}
	int cnt = n;
	x -= sum;

	sort(m.begin(), m.end());
	rep(i, n)
	{
		if (x / m[i])
		{
			cnt += x/m[i];
			x = x%m[i];
		}
	}
	cout << cnt << endl;
	return (0);
}