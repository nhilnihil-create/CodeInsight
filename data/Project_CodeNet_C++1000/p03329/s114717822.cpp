#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(x) (ll)x.size()
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> osSet;

using pll = pair<ll, ll>;

const ll maxN = 1e5;
const ll INF = 1e17;
const ll MOD = 1e9 + 7;

ll xs[] = {-1, 1, 0, 0, -1, 1, 1, -1};
ll ys[] = {0, 0, -1, 1, -1, 1, -1, 1};

ll segtree[maxN << 2];
ll lazy[maxN << 2];
ll A[maxN];

inline ll left(ll x){
	return x << 1;
}

inline ll right(ll x){
	return (x<<1) + 1;
}

ll func(ll x){
	return (x*(x+1))/2;
}

ll _pow(ll b, ll p){
	if(p == 0) return 1;
	if(p == 1) return b;
	ll exB = b*b;
	if(p&1) return b*_pow(exB, p/2);
	return _pow(exB, p/2);
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> vlp;
	for(ll i=1; _pow(6,i) < maxN; i++)
		vlp.emplace_back(_pow(6, i));
	for(ll i=1; _pow(9,i) < maxN; i++)
		vlp.emplace_back(_pow(9, i));
	vlp.emplace_back(1);
	sort(begin(vlp),end(vlp));
	ll dp[n+1];
	dp[0] = 1;
	for(ll i=1; i<=n;i++){
		dp[i] = INF;
		for(ll j=0; j<sz(vlp); j++){
			if(vlp[j] <= i)
				dp[i] = min(dp[i], 1+dp[i-vlp[j]]);
			else
				break;
		}
	}
	cout << dp[n]-1;
	return 0;
}