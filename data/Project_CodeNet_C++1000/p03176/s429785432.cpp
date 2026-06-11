#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
ll h[200001], a[200001], seg[800005];
ll merge(ll a, ll b) {
	return max(a, b);
}
ll query(ll pos, ll l, ll r, ll l1, ll r1) {
	if(l > r || r < l1 || l > r1) {
		return 0;
	}
	if(l1  <= l && r <= r1) {
		return seg[pos];
	}
	ll mid = (l + r) / 2;
	return merge(query(2*pos + 1, l, mid, l1 , r1), query(2*pos + 2, mid + 1, r, l1, r1));
}
void update(ll pos, ll l, ll r, ll x, ll val) {
	if(l > r || r < x || l > x) {
		return;
	}
	if(l == r) {
		seg[pos] = val;
		return; 
	}
	ll mid = (l + r) / 2;
	update(2*pos + 1, l, mid, x, val);
	update(2*pos + 2, mid + 1, r, x, val);
	seg[pos] = merge(seg[2*pos + 1], seg[2*pos + 2]);
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, i, ans = 0;
    cin>>n;
    for(i = 0; i < n; i++) {
    	cin>>h[i];
    }
    for(i = 0; i < n; i++) {
    	cin>>a[i];	
    }
    for(i = 0; i < n; i++) {
    	ll cur = a[i] + query(0, 0, n, 0, h[i] - 1);
    	ans = max(ans, cur);
    	update(0, 0, n, h[i], cur);
    }
    cout<<ans<<'\n';
}