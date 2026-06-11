#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n,m,x,y; cin >> n >> m >> x >> y;
	vector<int> xn(n);
	vector<int> ym(m);
	rep(i, n)
		cin >> xn[i];
	rep(i, m)
		cin >> ym[i];
	sort(xn.begin(), xn.end());
	sort(ym.begin(), ym.end());

	bool war = false;
	for (int i = 1; i <= y-x; i++)
	{
		if (xn.back() + i > x && xn.back() + i <= y)
		{
			if (xn.back() + i <= ym.front())
			{
				war = true;
			}
		}
	}
	if (war)
		cout << "No War\n";
	else
		cout << "War\n";
	return (0);
}