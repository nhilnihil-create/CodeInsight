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

const int maxn = 1e4+5;
int n;
ll a[maxn], b[maxn];


int main(){
	scanf("%d", &n);
	ll as = 0, bs = 0;
	for(int i = 0; i<n; i++) scanf("%lld", &a[i]), as+= a[i];
	for(int i = 0; i<n; i++) scanf("%lld", &b[i]), bs+= b[i];
	if (as >= bs){
		if(as==bs && equal(a, a+n, b, b+n)) puts("Yes");
		else puts("No");
		return 0;
	}
	ll M = bs-as;
	ll K = 0;
	for(int i = 0; i<n; i++){
		if (a[i]<b[i]) {
			ll movs = (b[i]-a[i]+1ll)/2ll;
			K+= movs;
			a[i]+=movs+movs;
		}
	}
	ll L = M - K;
	if (L<0) {puts("No"); return 0;}
	ll D = 0;
	for(int i = 0; i<n; i++) {
		if (b[i]<a[i]) D+= a[i]-b[i], b[i] = a[i];
	} 
	if (L+L == M-D) puts("Yes");
	else puts("No");
	return 0;
}
