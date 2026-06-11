#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 7;

int l[N], r[N];
set<pair<int, int> > L, R;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> l[i] >> r[i];
	}
	ll ans = 0;
	for (int x=0; x<2; x++)
	{
		for (int i=0; i<n; i++)
		{
			L.insert({l[i], i});
			R.insert({r[i], i});
		}
		int pos = 0;
		ll res = 0;
		for (int i=0; i<n; i++)
		{
			int turn = (i + x) % 2;
			int ind = 0;
			if (turn)
				ind = L.rbegin()->second;
			else
				ind = R.begin()->second;
			if (pos < l[ind])
				res += l[ind] - pos, pos = l[ind];
			else if (pos > r[ind])
				res += pos - r[ind], pos = r[ind];
			L.erase({l[ind], ind});
			R.erase({r[ind], ind});
		}
		ans = max(ans, res + abs(pos - 0));
	}
	cout << ans << "\n";
	return 0;
}
