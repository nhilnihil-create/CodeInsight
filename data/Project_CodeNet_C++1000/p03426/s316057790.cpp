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

const ll maxN = 1e7;
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
	ll n, m, d;
	cin >> n >> m >> d;
	ll a[n][m];
	pll P[(n*m)+1];
	for(ll i=0; i<n; i++){
		for(ll j=0; j<m; j++){
			cin >> a[i][j];
			P[a[i][j]] = mp(i+1, j+1);
		}
	}
	vector<ll> pref((n*m)+1, 0);
	for(ll i=1; i<=d; i++){
		ll li = P[i].f, lj = P[i].s;
		for(ll j=i; j<=(n*m)+1; j+=d){
			if(j == i)
				pref[j] = 0;
			else{
				pref[j] = pref[j-d] + abs(li-P[j].f) + abs(lj-P[j].s);
				li = P[j].f, lj = P[j].s;
			}
		}
	}
	ll t;
	cin >> t;
	while(t--){
		ll x, y;
		cin >> x >> y;
		cout << pref[y]-pref[x] << "\n";
	}
	return 0;
}