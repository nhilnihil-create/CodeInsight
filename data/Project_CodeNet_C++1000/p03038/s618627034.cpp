#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 100005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, a[MAXX], b[MAXX], c[MAXX];
vector<ll> adj[MAXX];
vector<pair<int, int> > v;
bool used[MAXX];
multiset<int> ms;

signed main()
{
	FAST;
	ll   r;
	ll m;
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		ms.insert(a[i]);
	}
	for(ll i = 0; i < m; i++){
		cin >> b[i] >> c[i];
		v.push_back({c[i] , b[i]});
	}
	sort(v.begin() , v.end());
	reverse(v.begin() , v.end());
	ll ans = 0;
	for(ll i = 0; i < v.size(); i++){
		ll x = v[i].first, y = v[i].second;
		while(*(ms.begin()) < x && y){
		ms.erase(ms.begin());
		ms.insert(x);
		y --;
	}
	}
	
	while(n){
		ans += *(ms.begin());
		ms.erase(ms.begin());
		n--;
	}
		
	cout << ans;
}