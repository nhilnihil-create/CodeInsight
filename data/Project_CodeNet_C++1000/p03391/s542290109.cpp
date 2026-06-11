#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

const int MAX = 1 << 18;

int a[MAX], b[MAX];

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	LL s = 0;
	int mn = INF;
	FOR(i, 0, n)
	{
		cin >> a[i] >> b[i];
		s += b[i];
		if(a[i] > b[i])
			mn = min(mn, b[i]);
	}
	cout << (mn == INF ? 0 : s - mn) << "\n";
	return 0;
}