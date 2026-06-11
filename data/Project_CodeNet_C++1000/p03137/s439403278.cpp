#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 200005


#define PI 3.14159265358979323846264338327950

#define ll  long long int
vector<ll> v;
multiset<ll> ms;
multiset<ll>::iterator it;
ll a[MAXX], b[MAXX];
ll mod = 1000000007;
char c[MAXX];

int main()
{
	FAST;
	ll  ans = 0, a1 = 0, a2 = 0, n , mx = 0, m;
	cin >> n >> m;
	for(ll i = 1; i <= m; i++){
		cin >> a[i];

	}
	sort(a+1, a+m+1);
	for(ll i = 2; i <= m; i++){
		b[a1] = a[i]- a[i-1];
		a1 ++;
	}
	sort(b, b + a1);
	reverse(b, b + a1);
	for(ll i = 0; i< a1; i++){
		ans += b[i];
		mx = max(mx, b[i]);
		
	}
	for(ll i = 0; i < n - 1 ; i ++){
		ans -= b[i];
	}
	if(n > m){
		ans = 0;
	}
	cout << ans;
	
}