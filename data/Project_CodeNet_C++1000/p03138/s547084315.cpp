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

const int M = 40;
const int N = 1e5;
ll a[N+5];
ll bit[M+5];
ll sum[M+5];

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll k;
	cin >> n >> k;
	ll tmp = k;
	int m = 0;
	while (tmp)
	{
		tmp >>= 1;
		m++;
	}
	REP(i, 0, n-1) cin >> a[i];

	REP(i, 0, n-1) REP(j, 0, m-1)
	{
		if (a[i] & (1LL << j))
			bit[j] -= (1LL << j);
		else
			bit[j] += (1LL << j);
	}

	REP(j, 0, m-1)
	{
		if (bit[j] > 0)
			sum[j] += bit[j];
		if (j > 0)
			sum[j] += sum[j-1];
	}

	ll init = 0;
	REP(i, 0, n-1) init += a[i];
	ll best = init;
	ll curr = 0;

	curr = init;
	REP(j, 0, m-1)
	{
		if (k & (1LL << j))
			curr += bit[j];
	}
	best = max(curr, best);

	REP(j, 0, m-1) if (k & (1LL << j))
	{
		curr = 0;
		REP(j2, j+1, m-1)
		{
			if (k & (1LL << j2))
				curr += bit[j2];
		}
		if (j > 0)
			curr += sum[j-1];
		best = max(best, init + curr);
	}

	cout << best << '\n';
	return 0;
}