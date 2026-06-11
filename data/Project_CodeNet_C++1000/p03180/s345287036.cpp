#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fastio() ios_base::sync_with_stdio(false);
#define rmod(x, y) ((((x)%(y))+(y))%(y))
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T, typename R = null_type, typename C = less<T>>
tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update> ordered_set(){
	return tree<T, R, C, rb_tree_tag, tree_order_statistics_node_update>();
}

const ll inf = 1e17;
const int maxn = 17, maxm = (1<<16)+5;
bool vis[maxn][maxm];
int n;
ll a[maxn][maxn], val[maxm], dp[maxm];

ll solve(int mask){
	if (dp[mask] != -1) return dp[mask];
	ll ret = -inf;
	for(int i = mask; i>0; i=(i-1)&mask){
		ret = max(ret, val[i]+solve(mask^i));
	}
	return dp[mask] = ret;
}


int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++) scanf("%lld", &a[i][j]);
	for(int i = 0; i<(1<<n); i++){
		if(__builtin_popcount(i) <= 1) val[i] = 0, dp[i] = 0;
		else for(int j = 0; j<n; j++) if ((i>>j)&1){
			for(int k = j+1; k<n; k++)
				if ((i>>k)&1) val[i]+=a[j][k];
		}
	}
	printf("%lld\n", solve((1<<n)-1));
	
	return 0;
}
