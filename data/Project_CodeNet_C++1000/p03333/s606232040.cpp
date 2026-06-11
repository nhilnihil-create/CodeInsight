#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

typedef long long ll;
ll n, s, l[N], r[N];
int main()
{
	ll i;
	cin >> n;
	l[0] = r[0] = 0;
	for (i = 1; i <= n; i++) {
		scanf ("%lld %lld", &l[i], &r[i]);
	}
	sort(l, l + n + 1, greater<ll>());
	sort(r, r + n + 1);
	for (i = 0; i <= n; i++) {
		if(l[i] - r[i] < 0) break;
		s += l[i] - r[i];
	}
	cout << s * 2;
    return 0;
}