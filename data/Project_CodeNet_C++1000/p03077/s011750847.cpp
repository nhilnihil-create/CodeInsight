#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

int     main()
{
	ll n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	ll m = min({a, b, c, d, e});
	cout << (n + m - 1) / m + 4 << endl;
}
