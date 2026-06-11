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
using vi = vector<int>;

//const ll INF = 1e18L + 5;
//const int INF = 1e9 + 5;
//const double pi = 3.14159265358979323846;

void	solve()
{
	int n;
	cin >> n;
	map<string, int> mp;
	bool ok = true;
	char tail;
	rep(i, n) {
		string s;
		cin >> s;
		mp[s]++;
		if ((i && s.front() != tail) || mp[s] >= 2)
			ok = false;
		tail = s.back();
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}