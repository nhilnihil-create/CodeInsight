// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define lu unsigned long long int
#define pi pair<ll, ll>
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for (ll i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define be begin
#define sz(a) (ll)(a.size())
#define INF 1e18
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
}

// ll mod = 1e9+7;

// ll mult(ll x, ll y){
//     ll rem=1;
//     while(y){
//         if(y&1){
//             rem=(rem*x)%mod;
//         }
//         x=(x*x)%mod;
//         y>>=1;
//     }
//     return rem;
// }


void solve(ll T){
	ll k;
	cin>>k;
	ve<ll>ar(k);
	lr(k) cin>>ar[i];
	if(ar[k-1]!=2){
		cout << "-1\n";
		return;
	}
	ll mn=ar[k-1], mx=2*ar[k-1]-1;
	for(ll i=k-2;i>=0;i--){
		ll a=mn/ar[i]+(mn%ar[i]!=0);
		if(a*ar[i]>mx){
			cout << "-1\n";
			return;
		}
		ll b=mx/ar[i];
		mn=a*ar[i];
		mx=b*ar[i]+ar[i]-1;
	}
	cout << mn << " " << mx << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// std::cout << std::unitbuf;
	ll T=1;
	// cin>>T;
	for(ll t=1;t<=T;t++){
		solve(t);
	}
	return 0;
}