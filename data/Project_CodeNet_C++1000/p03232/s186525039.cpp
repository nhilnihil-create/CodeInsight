#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005, MOD = 1000000007;

ll N, arr[MAXN], ps[MAXN];

ll pkt(ll a, ll b) {
	if (b == 0) return 1;
	else if (b&1) return a*pkt(a, b-1)%MOD;
	else {
		ll tmp = pkt(a, b/2);
		return tmp*tmp%MOD;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	ll nFact = 1;
	for (int i = 1; i <= N; i++) nFact = (nFact*i)%MOD;
	ps[0] = 0;
	for (int i = 1; i <= N; i++) {
		ps[i] = (ps[i-1] + nFact*pkt(i, MOD-2))%MOD;
	}
	
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = (ans + arr[i]*(ps[i] + ps[N+1-i] - ps[1]))%MOD;
		if (ans < 0) ans += MOD;
	}
	cout << ans << "\n";
	
	return 0;
}
