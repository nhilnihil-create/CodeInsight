#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	vector<int> b(n), out;

	rep(i, n) cin >> b[i];
	rep(i, n)
	{
		for(int j = b.size() - 1; j >= 0; j--)
		{
			if (b[j] == j + 1)
			{
				out.push_back(b[j]);
				b.erase(b.begin() + j);
				break;
			}
		}
	}
	reverse(out.begin(), out.end());
	if (out.size() == n)
	{
		rep(i, out.size())
			cout << out[i] << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}
