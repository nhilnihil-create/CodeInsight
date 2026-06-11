#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pi 3.141592653589793238
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define zip(i,a,b) for(int i=a;i<b;i++)
#define rzip(i,a,b) for(int i=a;i>=b;i--)
#define ll unsigned int
#define test int t;cin>>t; while(t--)
#define en '\n'
typedef pair<int, int>     pii;
typedef pair<char, int>    pci;
typedef pair<char, char>   pcc;
typedef vector<pii>       vii;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int)x.size()
#define INF (1e18+5)
#define inf (1e9+5)
#define mod 1000000007


void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
// You should only debug a pair of simple data types. For example,
// the debug won't work if one of pair's elements is collection type
// (std::vector, std::map, std::set...).
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


// bool check_prime(int n)  return whether a number is prime or not O(sqrt(N));
// int BE(int x,int n,int m)  return x^n%m; O(logN);
// void sieve()  from number 1-1000001 saare prime store kar lega  in bool is_prime[1000001] array
// vector<int> z_array(string s)  return vector which is Z-array of string s;
// vector<int> lps(string s)      return vector which is lps array of string s;
// int power(int x,int n) return x^n; O(logN);
// using_ordered_set (template for using ordered set , replace first 2 lines of this page with this code..);
const int gf = 1e6 + 9;
int dp[100009];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	if (fopen("input.txt", "r"))
	{
		freopen ("input.txt" , "r" , stdin);
		freopen ("output.txt" , "w" , stdout);
	}
#endif
	//_______________________________-code starts-_______________________________________________

	int n;
	cin >> n;
	vi v;
	int ans = 0;





	rep(i, 1, 5)
	v.pb(1);

	int x = 6;
	while (x <= 1e5)
	{
		v.pb(x);
		x *= 6;
	}
	x = 9;
	while (x <= 1e5)
	{
		v.pb(x);
		x *= 9;
	}
	debug(sz(v));
	rep(i, 1, 100000)
	{
		dp[i] = inf;
	}
	dp[0] = 0;

	// //dp[i][j]  sum is j using upto i-th element
	// zip(i, 0, sz(v))
	// {
	// 	dp[0][i] = 0;
	// }

	rep(i, 1, n)
	{
		zip(j, 0, sz(v))
		{
			if (i < v[j])
				continue;
			else
			{
				dp[i] = min(dp[i], dp[i - v[j]] + 1);
			}
		}
	}
	cout << dp[n] << en;






	return 0;
}


