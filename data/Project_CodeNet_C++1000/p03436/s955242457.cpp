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
char s[109][109];
int dp[109][109];
int vis[109][109];
int dis[109][109];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int h, w;

bool is_valid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < h && y < w)
		return true;
	else
		return false;
}

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


	cin >> h >> w;
	int cnt = 0;
	zip(i, 0, h)
	{
		zip(j, 0, w)
		{
			char x;
			cin >> x;
			s[i][j] = x;
			if (x == '.')
				cnt++;
		}
	}
	if (s[0][0] == '#')
	{
		cout << -1 << en;
		return 0;
	}

	queue<pii>q;
	q.push({0, 0});
	vis[0][0] = true;

	rep(i, 0, 100)
	{
		rep(j, 0, 100)
		dis[i][j] = inf;
	}
	dis[0][0] = 0;
	int x1, y1;

	while (sz(q))
	{
		pii node = q.front();
		int x = node.ff;
		int y = node.ss;
		q.pop();
		zip(i, 0, 4)
		{
			x1 = x + dx[i];
			y1 = y + dy[i];
			if (is_valid(x1, y1) == 0)
				continue;
			if (vis[x1][y1])
				continue;
			if (s[x1][y1] == '#')
				continue;
			vis[x1][y1] = 1;
			q.push({x1, y1});
			dis[x1][y1] = dis[x][y] + 1;
		}
	}
	if (dis[h - 1][w - 1] == inf)
	{
		cout << -1 << en;
		return 0;
	}
	cout << cnt - dis[h - 1][w - 1] - 1 << en;



	// dp[1][1] = (s[1][1] == '#');
	// rep(i, 2, w)
	// {
	// 	// dp[1][i]
	// 	dp[1][i] = dp[1][i - 1] + (s[1][i] == '#');
	// }
	// rep(i, 2, h)
	// {
	// 	dp[i][1] = dp[i - 1][1] + (s[i][1] == '#');
	// }
	// rep(i, 2, h)
	// {
	// 	rep(j, 2, w)
	// 	{
	// 		dp[i][j] = min(dp[i - 1][j] + s[i][j] == '#', dp[i][j - 1] + s[i][j] == '#');
	// 	}
	// }
	// cout << dp[h][w] << en;




	return 0;
}


