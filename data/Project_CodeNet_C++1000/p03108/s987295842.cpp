#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using vi  = vector<int>;
using ii  = pair<int,int>;
using vii = vector<ii>;
using ll  = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) int((x).size())
#define REP(i, a, b) for (auto (i) = (a); (i) <= (b); (i)++)
#define PER(i, a, b) for (auto (i) = (a); (i) >= (b); (i)--)
#define ITR(i, x) for (auto (i) = (x).begin(); (i) != (x).end(); (i)++)

string to_string(string s) { return '\"' + s + '\"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B> string to_string(pair<A,B> p)
{ return "(" + to_string(p.F) + ", " + to_string(p.S) + ")"; }
template <typename T> string to_string(T v) {
	int f = 0; string res = "{";
	for (const auto &x: v)
		res += (f++ ? ", " : "") + to_string(x);
	return res + "}";
}
void debug_out() { cerr << "]\n"; }
template <typename T, typename... V>
void debug_out(T a, V... v)
{ cerr << to_string(a); if (sizeof...(v)) cerr << ", "; debug_out(v...); }

#ifdef LOCAL // add -DLOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif // debug(var1, var2, ...);

const int N = 1e5;
ii edges[N+5];
ll ans[N+5];

vi p;
vi rnk;
vector<ll> sizes;
ll curr;

int find(int i)
{ return (p[i] == i ? i : p[i] = find(p[i])); }

ll getSize(int i)
{ return sizes[find(i)]; }

void unite(int i, int j)
{
	i = find(i); j = find(j);
	if (i == j)  return;
	curr -= getSize(i) * getSize(j);
	if (rnk[i] < rnk[j])
	{
		p[i] = j;
		sizes[j] += sizes[i];
	}
	else
	{
		p[j] = i;
		sizes[i] += sizes[j];
		if (rnk[i] == rnk[j])
			rnk[i]++;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;
	REP(i, 0, m-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		edges[i] = {x, y};
	}

	p.assign(n, 0);
	iota(ALL(p), 0);
	rnk.assign(n, 1);
	sizes.assign(n, 1LL);
	curr = n*(n-1)/2;

	PER(i, m-1, 0)
	{
		ans[i] = curr;
		unite(edges[i].F, edges[i].S);
	}
	REP(i, 0, m-1)
		cout << ans[i] << '\n';
	return 0;
}