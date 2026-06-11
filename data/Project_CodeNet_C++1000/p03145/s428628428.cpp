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
	cin >> a1 >> a2 >> n;
	mx = min(a1, min(a2, n));
	m = max(a1, max(a2, n));
	m = a1+ a2 + n - mx - m;
	cout << mx*m / 2;
	
}