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
const int INF = 1e9 + 47;
const LL LINF = INF *(LL) INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get(VI a, VI b, bool first)
{
	if (a == b) return 0;
	
	if (first)
	{
		int mx = 0;
		FOR(i, 0, SZ(a))
			if (a[i])
			{
				--a[i];
				mx = max(mx, 1 + get(a, b, first ^ 1));
				++a[i];
			}
			
		return mx;
	}
	else
	{
		int mn = INF;
		FOR(i, 0, SZ(b))
			if (b[i])
			{
				--b[i];
				mn = min(mn, get(a, b, first ^ 1));
				++b[i];
			}
			
		return mn;
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	int n;
	while(cin >> n)
	{
		VI a(n), b(n);
		FOR(i, 0, n) cin >> a[i] >> b[i];
		LL s = 0;
		FOR(i, 0, n) s += a[i];
		LL mn = s;
		FOR(i, 0, n) 
			if (a[i] > b[i]) mn = min(mn, (LL)b[i]);
		
		cout << s - mn << endl;
	}
	
	cerr << "Time elapsed: " <<  clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
