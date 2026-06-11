#include <bits/stdc++.h>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; i++) cin >> c[i];
#define exit_message(s) return 0*printf(s)
#define show(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, n) for (int i = 0; i < n; i++) cout << c[i] << " "; cout << "\n";
#define forl(i, a, n) for (int i = a; i < n; i++)
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vill;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long true_rand(long long n)
{
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b>>1);
	res = (res*res)%mod;
	if (b&1LL)
		res = (res*a)%mod;
	
	return res;
}

const int N = 2e5 + 5;

int n;
vi g[N] = {};
int vis[N] = {};

void dfs(int s)
{
	if (!vis[s])
		vis[s] = 1;
	for (auto e: g[s])
	{
		if (!vis[e])
		{
			vis[e] = vis[s] + 1;
			dfs(e);
		}
	}
}

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	forl(i, 0, n - 1)
	{
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	int mx = 0;
	forl(i, 1, n + 1)
	{
		if (vis[i] > vis[mx])
			mx = i;
	}
	memset(vis, 0, sizeof vis);
	dfs(mx);
	mx = 0;
	forl(i, 1, n + 1)
	{
		if (vis[i] > vis[mx])
			mx = i;
	}
	int diam = vis[mx];
	if (diam % 3 == 2)
		cout << "Second\n";
	else
		cout << "First\n";

	return 0;
}