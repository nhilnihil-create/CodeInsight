# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

ll n, p[xn], x, y, part[xn][xn], dp[xn][xn], a[xn][xn], b[xn];

int main(){
    InTheNameOfGod;
    
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++ i){
		cin >> p[i];
		b[p[i]] = i;
	}
	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= n; ++ j) part[i][j] = part[i][j - 1] + (p[j] < i);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j < i; ++ j) a[i][j] = a[i - 1][j];
		for (int j = i; j >= 1; -- j){
			if (a[i][j - 1] > p[i]) a[i][j] = a[i][j - 1];
			else{
				a[i][j] = p[i];
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i][j] = dp[i][j - 1] + x;
			int ind = b[a[i][j]];
			int ted = part[a[i][j]][i] - part[a[i][j]][ind];
			dp[i][j] = min(dp[i][j], dp[ind - 1][j - ted - 1] + ted * y);
		}
	}
	cout << dp[n][n] << endl;

    return 0;
}
