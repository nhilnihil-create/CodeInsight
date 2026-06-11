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
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

const int MAX = 1 << 18;
int n, m, k;
PII a[MAX];
vector<int> blocked[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	cin >> n >> m >> k;
	if (m < n)
	{
		FOR(i, 1, n + 1)
			blocked[i].PB(m + 1);
		m = n;
	}
	
	FOR(i, 1, n + 2)
		blocked[n + 1].PB(i);
	
	set<PII> b;
	FOR(i, 0, k)
	{
		cin >> a[i].X >> a[i].Y;
		blocked[a[i].X].PB(a[i].Y);
	}
	
	FOR(i, 1, n + 2)
		for(auto j: blocked[i])
			b.insert({i, j});
	
	FOR(i, 1, n + 1)
		sort(ALL(blocked[i]));
	
	if (n == 1 || b.count({2, 1}))
	{
		cout << 1 << endl;
		return 0;
	}
	
	int ans = INF;
	bool bula = 0;
	if (SZ(blocked[2]) && blocked[2][0] == 2)
		bula = 1;
	
	int prev_mx = 2;
	if (bula)
		--prev_mx;
	int mx;
	
	FOR(i, 3, n + 2)
	{		
		mx = prev_mx + 1;
		if (b.count({i, mx}))
			--mx;
		if (SZ(blocked[i]) && blocked[i][0] <= mx)
		{
			ans = i - 1;
			break;
		}
		
		prev_mx = mx;
	}
	
	ans = min(ans, n);	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}

