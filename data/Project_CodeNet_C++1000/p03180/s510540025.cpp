// Marcin Knapik
#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> // order_of_key
//#include <ext/pb_ds/tree_policy.hpp> // find by order
//using namespace __gnu_pbds; 
//#define ordered_set tree< int , null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  

// const ll MAX_LL = 0xFFFFFFFFFFFFFFFF;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define losuj(a, b) uniform_int_distribution<ull>(a, b)(rng)
#define losuj_real(a, b) uniform_real_distribution<long double>(a, b)(rng)

typedef long double             ld;
typedef long long               ll;
typedef unsigned long long      ull;
typedef pair<ll, ll>            pll;
typedef pair<int, int>          ii;
typedef vector<int>             vi;
typedef vector<ii>              vii;
typedef vector<vi>              vvi;
typedef vector<vector<ii>>      vvii;
typedef vector< ll >            vll;
typedef vector< pll >           vpll;
 
#define sz(a)                   (int)(a).size()
#define pb                      push_back
#define all(c)                  (c).begin(), (c).end()
#define rall(c)                 (c).rbegin(), (c).rend()
#define FOR(i, a)               for (int i = 0; i < (a); i++)
#define f                       first
#define s                       second
#define rr "\e[31m "
#define bb "\e[m "

template <class T> inline bool setmin(T &a, T b){if (a > b)return a = b, 1;return 0;}
template <class T> inline bool setmax(T &a, T b){if (a < b)return a = b, 1;return 0;}
 
template<class T> inline T fast(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> inline T russian(T a, T b, T mod) {ll res = 0; while(b){if(b&1) res = (res + a)%mod; a = (a+a)%mod; b>>=1;}return res;}
template <class T> istream &operator>>(istream &os, vector<T> &container){for (auto &u : container)os >> u;return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &container){for (auto &u : container)os << u << " ";return os;}
template<typename T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return a; }

const ll INF = 1e9 + 7;
const ll mod = 998244353;
const ll N = 1e6+7;
const ll T = 1<<20;
const ll BIG_INF = 1e18 + 7;

ll n, m;

ll koszt[N];
ll dp[N];
int tab[35][34];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	cin >> n;
	FOR(i, n)
		FOR(j, n)
			cin >> tab[i][j];
	FOR(i, (1<<n)){
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if(i & (1<<j) && i & (1<<k))
					koszt[i] += tab[j][k];
		for(int j = i; j > 0; j = (j-1)&i)
			dp[i] = max(dp[i], dp[i-j] + koszt[j]);
	}

	cout << dp[(1<<n)-1]/2 << '\n';
}	
