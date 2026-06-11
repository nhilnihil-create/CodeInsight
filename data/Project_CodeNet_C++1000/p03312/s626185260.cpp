#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)
 
#define INF 987654321
#define IINF 2987654321987654321
#define MOD 1000000007


const int MAXN = 2e5 + 50;
int n;
ll a[MAXN], s[MAXN];
void readInput() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i];
}


inline ll f(int i, int j, int k) {
	if(0 > i || i > j || j > k || k > n)
		return IINF;
	ll P = s[i], Q = s[j] - s[i], R = s[k] - s[j], S = s[n] - s[k];
	if(!(P && Q && R && S)) 
		return IINF;
	return max({P, Q, R, S}) - min({P, Q, R, S});
}


void solve() {
	ll mn = IINF;
	for(int x = 2; x <= n-2; x++) {
		int p = lower_bound(s+1, s+x+1, s[x]/2) - s;
		int q = lower_bound(s+x+1, s+n+1, (s[n] + s[x]) / 2) - s;
		for(int i : {p-1, p})
			for(int k : {q-1, q})
				mn = min(mn, f(i, x, k));
	}
	printf("%lld\n", mn);
}


int main() {
	readInput();
	solve();
}