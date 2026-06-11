#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 1005

#define PI 3.14159265358979323846264338327950

#define ll  int
vector<ll> v;
ll p[MAXX];
multiset<ll> ms;
multiset<ll>::iterator it;
signed main()
{
	FAST;
	ll   h = 0, t = 0; ll ans = 0;
	ll a, b, c;
	cin >> a >> b >> c;
	for(ll i = 1; i <= min(a, b); i++){
		if(a % i == 0 && b % i == 0){
			p[t] = i;
			t ++;
		}
	}
	reverse(p, p + t);
	cout << p[c-1];;
}