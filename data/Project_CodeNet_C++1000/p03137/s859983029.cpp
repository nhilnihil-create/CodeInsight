#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n, m; cin >> n >> m;
	vector<long> x(m);
	priority_queue<long> q;
	rep( i , m)
		cin >> x[i];
	sort(x.begin(), x.end());
	long sum = 0;
	if (m > 1)
	{
		rep(i, m - 1)
		{
			q.push( abs(x[i] - x[i+1]) );
			sum += abs(x[i] - x[i+1]);
		}
	}
	rep(i, n-1)
	{
		if (!q.empty())
		{
			sum -= q.top();
			q.pop();
		}
	}
	cout << sum << endl;
	return 0;
}
