#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n;
	cin >> n;
	vector<tuple<int, int, int> > tp;
	tuple<int, int, int> s = make_tuple(0, 0, 0);
	tp.push_back(s);
	string ans = "Yes";
	rep(i, n)
	{
		int t, x, y;
		cin >> t >> x >> y;
		int mp = abs(get<1>(tp.back()) - x) + abs(get<2>(tp.back()) - y);
		int time = abs(get<0>(tp.back()) - t);
		if (mp <= time)
		{
			if ((time % 2 && mp % 2==0) || (time % 2 == 0 && mp % 2))
				ans = "No";
		}
		else
			ans = "No";
		s = make_tuple(t,x,y);
		tp.push_back(s);
	}
	cout << ans << endl;
	return (0);
}
