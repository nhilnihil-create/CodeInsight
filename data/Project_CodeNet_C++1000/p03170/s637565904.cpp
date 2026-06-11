#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll              long long
#define rep(i,a)        for(ll i = 0 ; i < a ; i++)
#define repe(i,a,b)     for(ll i = a ; i < b ; i++)
#define bac(i,a)        for(ll i = a ; i >= 0 ; i--)
#define bace(i,a,b)     for(ll i = a ; i >= b ; i--)
#define pb              push_back
#define mp              make_pair
#define in              insert
#define ff              first
#define ss              second
#define vv              vector
#define vll             vector <ll>
#define pll             pair <ll,ll>
#define vpll            vector <pll>
#define umap            unordered_map
#define uset            unordered_set
#define mset            multiset
#define pqueue          priority_queue
#define stk             stack<ll>
#define que             queue<ll>
#define setbit(x)       __builtin_popcountll(x)
#define init(c,a)       memset(c,a,sizeof(c))
#define all(c)          c.begin(),c.end()
#define lb              lower_bound
#define ub              upper_bound
#define maxe            *max_element
#define mine            *min_element
#define gcd(a,b)        __gcd(a,b)
#define rev             reverse
#define Y               "YES"
#define N               "NO"
#define br              "\n"
#define sp              " "
#define debug(x)        cout << #x << " : " << x << endl;
const ll mod = 1000000007;
const ll MOD = 998244353;
const ll inf = 1e18;
const ll MAX = 2e5 + 1;


// ====== int_1024t begins ======
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// ====== int_1024t ends ======

inline ll add(ll a, ll b) {return ((a % mod) + (b % mod)) % mod;}
inline ll sub(ll a, ll b) {return ((a % mod) - (b % mod) + mod) % mod;}
inline ll mul(ll a, ll b) {return ((a % mod) * (b % mod)) % mod;}
ll pwr(ll x, ll n) {
	x = x % mod;
	if (!n) return 1;
	if (n & 1) return mul(x, pwr(mul(x, x), (n - 1) / 2));
	else return pwr(mul(x, x), n / 2);
}
// O(nlogn) for [1,n]
ll modinv(ll n) {
	return pwr(n, mod - 2);
}
// O(logn) for[1,n]
ll inv(ll i) {
	if (i == 1) return 1;
	return (MOD - (MOD / i) * inv(MOD % i) % MOD) % MOD;
}
// =============================



void solve()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<bool> dp(k + 1, false);

	for (int index = 1; index <= k; index++)
	{
		for (int i = 0; i < n; i++)
		{
			if ((index - a[i]) >= 0 && dp[index - a[i]] == false)
			{
				dp[index] = true;
				break;
			}
		}
	}

	if (dp[k])
		cout << "First";
	else
		cout << "Second";

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;

	solve();


	return 0;
}