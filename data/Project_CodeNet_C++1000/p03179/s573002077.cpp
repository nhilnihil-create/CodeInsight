#include <bits/stdc++.h>                                           
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
using namespace std;
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;
typedef unsigned long long ull;         
typedef vector < pii > vpii;
typedef vector < int > vi;
typedef long double ldb; 
typedef long long ll;  
typedef double db;                         
 
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, N = 3e3 + 48, mod = 1e9 + 7, maxn = 102;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;


int n, dp[N][N], pr[N][N];
string s;

void add (int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int get (int l, int r, int tp) {
	if (l > r)
		return 0;
	return (dp[tp][r] - dp[tp][l - 1] + mod) % mod;
}

main () {
	cin >> n >> s;
	dp[1][1] = 1;
	
	s = "##" + s;
	forn (i, 2, sz(s) - 1)	
		forn (j, 1, i) {
			dp[i][j] = dp[i][j - 1];
			if (s[i] == '<') 
				add(dp[i][j], dp[i - 1][j - 1]);
			else
				add(dp[i][j], get(j, i - 1, i - 1));
		}

	
	cout << dp[n][n] << endl;
} 