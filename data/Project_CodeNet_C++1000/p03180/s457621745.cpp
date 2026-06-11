#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int MOD2 = 998244353;
const int MOD = 1000000007;
using namespace std;
#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);
#define fi first
#define se second
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
#define is_empty(...) ( sizeof( (char[]){#__VA_ARGS__} ) == 1 )

void print() {}
template<typename T, typename... Args>
void print(T firstArg, Args... args) {
	#ifdef LOCAL
	cout << firstArg << endl;
	print(args...);
	#endif
}

//endregion

/* Notes:
 * Fry my kartoshka
 */

const int MAXN = 17;
const int INF = 2e9;
const ld PI = 3.14159265358979323846;

int a[MAXN][MAXN];
ll dp[1 << MAXN + 1];
ll add[1 << MAXN + 1];

const int REV = (1 << 31) - 1;

int main(){
	//usaco("milkvisits");

#ifdef LOCAL
	setIn("in.txt");
	setOut("out.txt");
#endif

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	dp[0] = 0;

	for(int i = 1; i < (1 << n) + 1; i++){
		dp[i] = -INF;
	}

	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				for(int j = 0; j < n; j++){
					if(mask & (1 << j)){
						add[mask] += a[i][j];
					}
				}
			}
		}

		add[mask] /= 2;
	}

	ll ans = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		int rem = ((1 << n) - 1) ^ mask;
		for(int sub = rem; sub > 0; sub = (sub - 1) & rem){
			dp[mask | sub] = max(dp[mask | sub], dp[mask] + add[sub]);
			ans = max(ans, dp[mask | sub]);
		}
	}
	cout << dp[(1 << n) - 1];
}
