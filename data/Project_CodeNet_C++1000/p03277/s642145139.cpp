//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

//# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
 
int n, m, k;
int a[N];
int b[N];
int tong[N];
//	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//	shuffle(permutation.begin(), permutation.end(), rng);



bool check (int x) {
	/*ordered_set < pair < int, int > > q;
	ll ans = 0;
	q.insert({0, 0});
	for (int i = 1; i <= n; ++i) {
		b[i] = b[i-1];
		if (a[i] >= x) b[i]++;
		else b[i]--;
		ans += q.order_of_key({b[i], n+1});
  		q.insert({b[i], i});
	}*/
	memset(tong,0,sizeof(tong));
	int dq = n, dd = 1; ll ans = 0;
	tong[n] = 1; 
	for(int i=1;i<=n;i++){
		if(a[i] >= x) dd += tong[++dq];
		else dd -= tong[dq--];
		
		ans += dd++; 
		tong[dq]++;
	}
	ll overall = n * (ll)(n+1) / 2;

	return ans * 2 >= overall;
}

int main () {
	scanf("%d", &n);
	vector < int > val;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		val.pb(a[i]);
	}
	sort(every(val));
	val.resize(unique(every(val)) - val.begin());

	int l = 0, r = sz(val);
	while (r - l > 1) {
		int md = (l + r) >> 1;
		if (check(val[md])) {
			l = md;
		} else {
			r = md;
		} 
	}

	printf("%d\n", val[l]);

	return Accepted;
}

// B...a