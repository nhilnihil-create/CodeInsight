#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll  long long int
vector<ll> v;
multiset<ll> ms;
multiset<ll>::iterator it;
ll a[MAXX], b[MAXX];
int main()
{
	FAST;
	ll n, t, m, o = 1, z, p, ans = 0;
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> t;
		for(ll i = 0; i < t; i++){
			cin >> a[i];
			b[a[i]] ++;
		}
	}
	for(ll i = 1; i <= m; i++){
		if(b[i] == n){
			ans ++;
		}
	}
	cout << ans;
	

}