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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n;
VI g[N];
char used[N];
int d[N];

void bfs(int v)
{
	FILL(used, 0);
	used[v] = 1;
	d[v] = 0;
	queue<int> q;
	q.push(v);
	
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		for(auto i: g[v])
			if (!used[i])
			{
				used[i] = 1;
				d[i] = d[v] + 1;
				q.push(i);
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		g[u].PB(v);
		g[v].PB(u);
	}
	
	bfs(1);
	int mx = 1;
	FOR(i, 2, n + 1)
		if (d[i] > d[mx])
			mx = i;
	
	bfs(mx);
	mx = 1;
	FOR(i, 2, n + 1)
		if (d[i] > d[mx])
			mx = i;
	
	mx = d[mx];
//	debug(mx)
	if (mx % 3 == 1)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
