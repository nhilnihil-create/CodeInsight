#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

typedef long long ll;
ll n, m, ans, z, s[3], v[N];
vector<ll> a[N];
void f(ll p, ll q) {
	ll i;
	if (v[p] != 0 && q != v[p]) z = 1;
	if (v[p] != 0) return;
	v[p] = q;
	s[q]++;
	for (i = 0; i < a[p].size(); i++) {
		f(a[p][i], 3 - q);
	}
}

//ll g(ll p) {
//	if (p <= 2) return 0;
//	return p * (p - 1) / 2 - (p - 1);
//}
int main()
{
	ll i, t1, t2;
	cin >> n >> m;
	for (i = 0; i <m; i++) {
		scanf ("%lld %lld", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	f(1, 1);
	if(z == 1) ans = n * (n - 1) / 2;
	else ans = s[1] * s[2];
	ans -= m;
//	ans += g(s[1]);
//	ans += g(s[2]);
	cout << ans << endl;
    return 0;
}
