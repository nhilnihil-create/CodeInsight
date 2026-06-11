///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef long long ll;
typedef double dd;
typedef long double ldd;
typedef pair <int, int> pii;
typedef pair <pii , int> ppii;
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define smax(x , y) x = max(x , y)
#define mp make_pair
#define all(x) x.begin() , x.end()
#define debug(x) cerr<< #x << " = " << x << endl
#define ddebug(x, y) cerr<< #x << " = " << x  << ", " << #y << " = " << y << endl
#define uop(x, y) pii(min(x, y), max(x, y))
#define mem(a, b) memset(a, b, sizeof a)
#define sq(x) (x) * (x)
#define out return cout << "NO" << endl, 0
//const int mx = 1e5 + 10;
int dp[305][305][305];
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int k, n;
	cin >> s >> k;
	n = sz(s);
	for(int l = n - 1; ~l; l--)
		for(int r = l + 1; r <= n; r++)
			for(int t = 0; t <= k; t++){
				if(r - l == 1){
					dp[l][r][t] = 1;
					continue;
				}
				if(s[l] == s[r - 1])
					dp[l][r][t] = dp[l + 1][r - 1][t] + 2;
				else{
					dp[l][r][t] = max(dp[l + 1][r][t] , dp[l][r - 1][t]);
					if(t)
						smax(dp[l][r][t] , dp[l + 1][r - 1][t - 1] + 2);
				}
			}
	cout << dp[0][n][k] << endl;
	return 0;
}


