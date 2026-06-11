#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
const int N = 1e6+5;	
ll get(vector<ll>&v, ll idx)
{
	ll ans = 0;
	while(idx >= 0)
	{
		ans = max(ans, v[idx]);
		idx = (idx & (idx+1)) - 1;
	}
	return ans;
}
void upd(vector<ll>&v, ll idx, ll val)
{
	while(idx < v.size())
	{
		v[idx] = max(v[idx], val);
		idx |= (idx + 1);
	}
}
 
int main()
{
	sync;
	ll n;
	cin >> n;
	vector<ll> bit(n + 1);
	ll h[n], a[n];
	input(h, n);
	input(a, n);
	for(ll i = 0; i < n; i++)
	{
		ll maxm = get(bit, h[i]) + a[i];
		upd(bit, h[i], maxm);
	}
	cout << get(bit, n);
}
