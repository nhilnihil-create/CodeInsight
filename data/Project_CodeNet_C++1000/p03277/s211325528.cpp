#pragma GCC optimize "03"
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

#define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update>

int n, a[N], b[N];

int f(int x){
	ordered_set pbds;
	int ans = 0;
	pbds.insert({0, 0});
	for(int i = 1; i <= n; i++){
		if(a[i] >= x)
			b[i] = 1;
		else
			b[i] = -1;
		b[i] += b[i-1];
		ans += pbds.order_of_key({b[i]+1, 0});
		pbds.insert({b[i], i});
	}
	return ans;
}
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, h = inf, x = n*(n+1)/2;
	x = (x-1)/2 + 1;
	while(l + 1 < h){
		int md = (l + h) >> 1;
		if(f(md) >= x)
			l = md;
		else
			h = md;
	}	
	cout << l;
	return 0;
}
