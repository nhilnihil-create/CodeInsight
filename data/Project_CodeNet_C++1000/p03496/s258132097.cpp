#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<PII> all_positive(int n)
{
	vector<PII> ans;
	FOR(i, 0, n - 1) ans.PB({i, i + 1});
	return ans;
}

vector<PII> all_negative(int n)
{
	vector<PII> ans;
	RFOR(i, n, 1) ans.PB({i, i - 1});
	return ans;
}

const int N = 1 << 10;
int n;
int a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	FOR(i, 0, n) cin >> a[i];
	vector<PII> ans;
	
	int mx = -INF, mn = INF;
	FOR(i, 0, n)
	{
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	
	if (mx + mn >= 0)
	{
		int pos = -1;
		FOR(i, 0, n) if (a[i] == mx) pos = i;
		FOR(i, 0, n) if (i != pos) ans.PB({pos, i});
		auto tut = all_positive(n);
		for(auto i: tut) ans.PB(i);
	}
	else
	{
		int pos = -1;
		FOR(i, 0, n) if (a[i] == mn) pos = i;
		FOR(i, 0, n) if (i != pos) ans.PB({pos, i});
		auto tut = all_negative(n);
		for(auto i: tut) ans.PB(i);
	}
	
	cout << SZ(ans) << endl;
	for(auto i: ans) cout << i.X + 1 << ' ' << i.Y + 1 << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
