#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//#include <ext/rope>
using namespace std;
#define ll long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define for0(i, a, b) for(int i = a; i < b; ++i)
#define for1(i, a, b) for(int i = a; i <= b; ++i)
#define forw0(i, a, b) for(int i = a - 1; i >= b; --i)
#define forw1(i, a, b) for(int i = a; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ii> vii;

const ll mod1 = 1e9 + 7, mod2 = 998244353, K = 26, maxn = 1 << 18;
const double pi = acos(-1);
ll N, n, ans[maxn], a[maxn];
vll dp[maxn];

void solve(){
	cin >> N; n = 1 << N;
	for0(i, 0, n){
		cin >> a[i]; dp[i].pb(a[i]);
	}
	for0(bit, 0, N){
		for0(i, 0, n){
			if(((i >> bit) & 1) == 0){
				fora(v, dp[i]){
					dp[i | (1 << bit)].pb(v);
				}
				sort(dp[i | (1 << bit)].rbegin(), dp[i | (1 << bit)].rend());
				while(dp[i | (1 << bit)].size() > 2){
					dp[i | (1 << bit)].pop_back();
				}
			}
		}
	}
	for0(i, 1, n){
		ans[i] = max(ans[i], ans[i - 1]);
		ans[i] = max(ans[i], dp[i][0] + dp[i][1]);
	}
	for0(i, 1, n) cout << ans[i] << '\n';
}

signed main(){
	//freopen(".inp", "r", stdin); freopen(".out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}

