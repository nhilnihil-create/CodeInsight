#include <bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORD(i, m, n) for (int i = m; i >= n; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 0; i <= n; ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int ans = 1000;
	REP(i, s.length() - 2)
	{
		int s1 = stoi(s.substr(i, 3));
		if (abs(753 - s1) < ans)
			ans = abs(753 - s1);
	}
	cout << ans << endl;

	return 0;
}
