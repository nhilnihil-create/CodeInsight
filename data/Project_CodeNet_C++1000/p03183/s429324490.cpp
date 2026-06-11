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

struct box{
	int w, s; ll v;
	bool operator<(box&b){return w+s<b.w+b.s;}
};

const int maxn = 1e3+5, maxs = 2e4+5;
int n;
box a[maxn];
ll dp[maxn][maxs];

int main(){
	scanf("%d", &n);
	for(int i = 1; i<=n; i++) scanf("%d %d %lld", &a[i].w, &a[i].s, &a[i].v);
	sort(a+1, a+n+1);
	for(int i = 1; i<=n; i++){
		for(int s = 0; s<maxs; s++){ // weight
			dp[i][s] = dp[i-1][s];
			if (s>=a[i].w && s-a[i].w<=a[i].s) 
				dp[i][s] = max(dp[i][s], dp[i-1][s-a[i].w]+a[i].v);
		}
	}
	
	printf("%lld\n", *max_element(dp[n], dp[n]+maxs));
	return 0;
}
