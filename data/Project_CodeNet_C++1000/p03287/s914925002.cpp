/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 100005
#define fi(a, b, c, d) for(int a = b; i < c; i += d)
#define fl(a, b, c, d) for(ll a = b; i < c; i += d)
#define quit exit(0)

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
vector<ll> V;
map<ll, ll> mp;
ll ans;


int main() {
	scanf("%lld %lld", &N, &M);
	data[0] = 0;
	fi(i, 0, N, 1) {
		scanf("%lld", &arr[i]);
		data[i + 1] = data[i] + arr[i];
	}
	mp[0] = 1;
	fi(i, 1, N + 1, 1) {
		cerr << data[i] << " ";
	}
	fi(i, 1, N + 1, 1) {
		ans += mp[data[i] % M];
		mp[data[i] % M]++;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
	Powered by Buggy Plugin
*/


