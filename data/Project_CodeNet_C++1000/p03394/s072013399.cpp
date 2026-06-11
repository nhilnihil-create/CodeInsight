# include <bits/stdc++.h>

using namespace std;
#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n;
int dp[20002][6];


int main () {
	SpeedForce;
	cin >> n;
	if (n == 3) {
		cout << "2 5 63\n";
		exit(0);
	}
	if (n == 4) {
		cout << "2 5 20 63\n";
		exit(0);
	}

	int a = n%3 ? n - 2 : n - 4;
	if (a > 15000) a = a % 2 ? 14999 : 15000;
	for(int i = 1; i <= a; i ++) cout << 2 * i << ' ';
	for (int i = 0; i < n-a; i ++) cout << 6 * i + 3 << ' ';

	return Accepted;
}

// B...a