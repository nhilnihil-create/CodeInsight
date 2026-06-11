// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define f first
#define s second
#define pb push_back
#define REP(i,a,b) for(long long int i=a ; i<b ; i++)
#define mp make_pair
#define mt make_tuple
#define INF 1000000000000000000
#define mod 1000000007
#define pi pair<ll,ll>
#define pd pair<ld,ld>
#define tp tuple<ll,ll,ll>
#define td tuple<ld,ld,ld>
#define vi vector<ll>
#define vd vector<ld>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvd vector<vd>
#define vpi vector<pi>
#define vpd vector<pd>
#define vs vector<string>
#define vvs vector<vs>
#define us unordered_set<ll>
#define um unordered_map<ll,ll>
#define MXPQ priority_queue<ll>
#define MNPQ priority_queue<ll,vi,greater<ll> >
#define sortA(a) sort(a.begin(),a.end())
#define sortD(a) sort(a.begin(),a.end(),greater<ll>())
#define all(a) a.begin(),a.end()
#define bll __builtin_popcountll
#define N 200005
const ld PI = acos(-1);

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
#define in insert
#define fbo find_by_order
#define ook order_of_key

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(char s) {
	string x = "";
	x += s;
	return x;
}

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t sze>
string to_string(bitset<sze> v) {
	string res = "";
	for (size_t i = 0; i < sze; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << to_string(H);
	debug_out(T...);
}
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

ll powmod(ll a, ll b, ll p) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % p;
		}
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}
void print1D(vi a)
{
	for (ll i = 0; i < (ll)a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void print2D(vector<vi> a)
{
	for (ll i = 0; i < (ll)a.size(); ++i)
	{
		for (ll j = 0; j < (ll)a[i].size(); ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
vi h(N), a(N);
vi T(4 * N);
ll rangeQuery(ll v, ll tl, ll tr, ll l, ll r)
{
	if (l > r)
	{
		return 0;
	}
	if (l == tl && r == tr)
	{
		return T[v];
	}
	ll tm = (tl + tr) / 2;
	return max(rangeQuery(2 * v, tl, tm, l, min(r, tm)), rangeQuery(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
	if (tl == tr)
	{
		T[v] = new_val;
	}
	else
	{
		ll tm = (tl + tr) / 2;
		if (pos <= tm)
			update(2 * v, tl, tm, pos, new_val);
		else
			update(2 * v + 1, tm + 1, tr, pos, new_val);
		T[v] = max(T[2 * v], T[2 * v + 1]);
	}
}
void solve()
{
	ll n;
	cin >> n;
	for (ll i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 0; i < n; ++i)
	{
		ll x = rangeQuery(1, 0, N - 1, 1, h[i] - 1);
		ans = max(ans, a[i] + x);
		update(1, 0, N - 1, h[i], a[i] + x);
	}
	cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
}

