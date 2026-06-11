#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//const ll INF = 1e18L + 5;
//const int INF = 1e9 + 5;
//const double pi = 3.14159265358979323846;

void	solve()
{
	string s;
	cin >> s;

	reverse(all(s));
	int n = s.size();
	int ans = 0;
	rep(i, n - 1) {
		if (s[i] - '0' < 9) {
			ans += s[n - 1] - '0' - 1;
			ans += 9 * (n - 1);
			cout << ans << endl;
			return;
		}
	}
	ans += s[n - 1] - '0';
	ans += 9 * (n - 1);
	cout << ans << endl;

}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
