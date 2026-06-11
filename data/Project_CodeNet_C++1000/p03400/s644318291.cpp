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

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, d, x;
	cin >> n >> d >> x;

	int ans = n + x;
	while (n--) {
		int a;
		cin >> a;
		int i = 1;
		while (i * a + 1 <= d) {
			ans++;
			i++;
		}
	}
	cout << ans << endl;
}