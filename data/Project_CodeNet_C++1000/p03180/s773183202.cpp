/*
ID: awesome35
LANG: C++14
TASK: milk4
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define mp make_pair
#define rsz resize
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define cont continue
#define endl '\n'
#define ednl '\n'
#define test int testc;cin>>testc;while(testc--)
#define pq priority_queue
const ll linf = 4000000000000000000LL;
const ll inf = 1000000007;//998244353//100000000003LL
const ld pi = 3.1415926535;


ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
ll minimum(ll x, ll y)
{
	if (x < y)
		return x;
	return y;
}
void pv(vi a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vll a) { trav(x, a)cout << x << " "; cout << endl; }void pv(vector<vi>a) {
	F0R(i, a.size()) { cout << i << endl; pv(a[i]); cout << endl; }
}void pv(vector<vll>a) { F0R(i, a.size()) { cout << i << endl; pv(a[i]); }cout << endl; }void pv(vector<string>a) { trav(x, a)cout << x << endl; cout << endl; }
/*
void dijkstra(int i)
{//Preconditions for this to work: 1. no negative edges. 2. dist and parents are both initialized with size N and full of INT_MAX and 0 respectively while dist[i]=0 and parent[i]=-1
	priority_queue<pii>todo;
	vi finalized;
	finalized.rsz(N + 1, 0);//make sure that the size of adjacency is N+1
	todo.push(mp(0, i));
	while (!todo.empty())
	{//.s is indexs while .f is weight
		pii temp = todo.top();
		int indexs = temp.second;
		todo.pop();
		if (finalized[indexs])continue;
		finalized[indexs] = 1;
		trav(x, adjacency[indexs])
		{
			if (finalized[x.first])
				continue;
			if (dist[x.f] > x.s + dist[indexs])
			{
				dist[x.first] = x.second + dist[indexs];
				parents[x.f] = indexs;
				todo.push(mp(-dist[x.first], x.f));
			}
		}
	}
}
void build_primes()
{
	primes.reserve(50000);
	vi visited;
	visited.rsz(200000, 0);
	FOR(i, 2, 200000)
	{
		if (visited[i] == 0)
		{
			primes.pb(i);
			a = i;
			while (a < 200000)
			{
				visited[a] = 1;
				a += i;
			}
		}
	}
}
//Prim's Algorithm
// need vector<vpi>adjacency
ll prim()
{
	ll a = 0;
	vi visited;
	visited.rsz(n, 0);
	visited[0] = 1;
	pq<pii>todo;
	trav(x, adjacency[0])
		todo.push({ -x.s,x.f });
	F0R(i, n - 1)
	{
		pii temp = todo.top();
		todo.pop();
		int indexs = temp.s;
		if (visited[indexs])cont;
		a -= temp.f;
		visited[indexs] = 1;
		trav(x, adjacency[indexs])
			if (visited[x.f] == 0)
			{
				todo.push({ -x.s,x.f });
			}
	}
	return a;
}
vector<vector<ll>> matrix_mult(vector<vector<ll>>& a, vector<vector<ll>>& b)
{
	int n = a.size();
	vector<vector<ll>> answer;
	answer.resize(n);
	for (int i = 0; i < n; i++) answer[i].resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) // calculate answer[i][j]
		{
			for (int k = 0; k < n; k++)
				answer[i][j] = (answer[i][j] + a[i][k] * b[k][j]) % inf;
		}
	}
	return answer;
}
vector<vector<ll>> matrix_exp(vector<vector<ll>>& a, ll n)
{
	vector<vector<ll>> result;
	result.resize(a.size());

	for (int i = 0; i < a.size(); i++)
	{
		result[i].resize(a[0].size(), 0);
		result[i][i] = 1;
	}
	while (n != 0)
	{
		if (n & 1)
			result = matrix_mult(result, a);
		a = matrix_mult(a, a);
		n = n >> 1;
	}
	return result;
}
// Union-Find
int find(int a) // return the root for node a
{
	if (a == links[a])
		return a;
	return links[a] = find(links[a]);
}
bool same(int a, int b) // check if node a and b has the same root
{
	return find(a) == find(b);
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (sizes[a] < sizes[b]) swap(a, b);
	sizes[a] += sizes[b]; //a always bigger than b, move subtree b under a
	links[b] = a;
}
*/
int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient 
		int q = a / m;
		int t = m;

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t;
		t = y;

		// Update y and x 
		y = x - q * y;
		x = t;
	}

	// Make x positive 
	if (x < 0)
		x += m0;

	return x;
}
ll power(ll x, ll y)
{
	ll k = 1 << 30;
	ll z = 1;
	while (k != 0)
	{
		z *= z;
		z %= inf;
		if (y >= k)
		{
			z *= x;
			z %= inf;
			y -= k;
		}
		k >>= 1;
	}
	return z;
}
// remember that you need to take abs
long double area(pii x, pii y, pii z)
{
	return ((ll)x.s * y.f + (ll)y.s * z.f + (ll)z.s * x.f - (ll)x.f * y.s - (ll)y.f * z.s - (ll)z.f * x.s) / 2.0;
}
bool clockwise(pii x, pii y, pii z)
{
	return area(x, y, z) > 0;
}
struct point
{
	ld x, y;
};
long double area(point x, point y, point z)
{
	return (x.y * y.x + y.y * z.x + z.y * x.x - x.x * y.y - y.x * z.y - z.x * x.y) / 2.0;
}
bool clockwise(point x, point y, point z)
{
	return area(x, y, z) > 0;
}
int gcd(int a, int b)
{
	if (a > b)swap(a, b);
	if (a == 0)return b;
	return gcd(a, b % a);
}
int popcount(int a)
{
	int count = 0;
	while (a != 0)
	{
		count += (a % 2);
		a >>= 1;
	}
	return count;
}
ll choose(ll n, ll r)
{
	ll p = 1, k = 1;
	if (n - r < r)
		r = n - r;
	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			long long m = gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}
	else
		p = 1;
	return p;
}
//end of preprogrammed methods
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen((s + ".in").c_str(), "r", stdin);
	//freopen((s + ".out").c_str(), "w", stdout);
}
int n, total;
vll sum, dp; vector<vll>a;
vi powers;
ll add(int mask)
{
	F0R(i, n)
	{
		if (mask & powers[i])
		{
			ll ans = 0;
			FOR(j, i + 1, n)
			{
				if (mask & powers[j])
					ans += a[i][j];
			}
			return ans + sum[mask - powers[i]];
		}
	}
	return 0;
}
vi b;
int mask1 = 0, mask2 = 0;
void solve(int mask)
{
	F0R(i, n)
	{
		if (b[i] == 3) { b[i] -= 3; b[i + 1]++; mask2 -= powers[i]; mask1 -= powers[i]; }
		else
		{
			if (b[i] == 1)
			{
				mask1 += powers[i];
			}
			else if (b[i] == 2)
			{
				mask2 += powers[i];
			}
			break;
		}
	}/*
	F0R(i, n)
	{
		if (b[i] == 1)
		{
			mask1 += powers[i];
		}
		else if (b[i] == 2)
		{
			mask1 += powers[i];
			mask2 += powers[i];
		}
	}*/
	if (mask2)
		dp[mask1] = max(dp[mask1], dp[mask1 - mask2] + sum[mask2]);
}
int main()
{
	setIO("test3");
	cin >> n; powers.rsz(n + 1); powers[0] = 1; F0R(i, n)powers[i + 1] = powers[i] << 1; total = powers[n];
	a.rsz(n, vll(n)); F0R(i, n)F0R(j, n)cin >> a[i][j];
	sum.rsz(total); dp.rsz(total);
	F0R(i, total)
	{
		sum[i] = add(i);
	}
	//pv(sum);
	int total1 = pow(3, n);
	b.rsz(n);
	F0R(i, total1)
	{
		solve(i);
		b[0]++;
	}
	//pv(dp);
	cout << dp[total - 1] << endl;
}