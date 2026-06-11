#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF*INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
LL mod = 1000LL*1000*1000 + 7;

VI g[200005];
PII dfs(int v, int p=-1, int d=0)
{
	PII res = MP(v,d);
	FOR(i,0,SZ(g[v]))
	{
		int to = g[v][i];
		if(to==p)
			continue;
		PII x = dfs(to,v,d+1);
		if(x.s>res.s)
			res = x;
	}
	return res;
}

string solve(int x)
{
	if(x%3==1)
		return "Second";
	else
		return "First";
}

int main()
{
	ios_base::sync_with_stdio(0); double startClock = clock();
	int n;
	cin >> n;
	FOR(i,0,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].PB(b);
		g[b].PB(a);
	}
	PII x = dfs(0);
	x = dfs(x.f);
//	cout << x.s;
	cout << solve(x.s);
	cerr << endl << (clock() - startClock)/CLOCKS_PER_SEC << endl;return 0;
}
