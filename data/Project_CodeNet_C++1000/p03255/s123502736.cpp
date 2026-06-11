#include<map>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;
ll const MAX = 200005;
ll const INF = 9200000000000000000;
ll a[MAX];
ll b[MAX];
ll f(ll p, ll q) {
	if (q <= 0) {
		return b[p] - 0;
	}
	else {
		return b[p] - b[q];
	}
}

int main() {
	ll n, x;
	cin >> n >> x;
	ll ttl = 0;
	REP(i, 1, n) {
		cin >> a[i];
		ttl += a[i];
		a[i] *= 2;
	}
	ll ans = INF;
	b[0] = 0;
	REP(i, 1, n) {
		b[i] = b[i - 1] + a[i];
	}
	for (ll i = n; i >= 1; i--) {
		ll cnt = 0;
		cnt += x * i;
		ll v = 0;
		cnt += f(n, n - i);
		for (ll j = n; j >= 1; j -= i) {
			cnt += f(j, j - i)*v;
			v++;
			if (cnt > ans) { break; }
		}
		ans = min(cnt, ans);
	}
	ans = ans + n * x + 3 * ttl;
	std::cout << ans << endl;
}