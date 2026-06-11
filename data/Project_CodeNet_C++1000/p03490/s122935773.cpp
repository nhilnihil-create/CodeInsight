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
const int N = 16023;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int x, y, c;
bool d, t[2][N], v[2][N];
string s;

int main() {
	int i, j;
	cin >> s >> x >> y;
	v[1][8000] = 1;
	for (i = 0; s[i] == 'F'; i++);
	v[0][8000 + i] = 1;
	for (; i <= s.size(); i++) {
		if (s[i] == 'F') c++;
		else {
			for (j = c; j < N - c; j++) {
				t[d][j - c] = max(t[d][j - c], v[d][j]);
				t[d][j + c] = max(t[d][j + c], v[d][j]);
			}
			for (j = 0; j < N; j++) v[d][j] = t[d][j], t[d][j] = 0;
			c = 0;
			d = !d;
		}
	}
    cout << (v[0][x + 8000] & v[1][y + 8000] ? "Yes" : "No") << endl;
   	return Accepted;
}

// B...a