#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e18+5;

int a[405];
ll memo[405][405];
ll pref[405];

ll sum(int l, int r) {
	if (l == 0) return pref[r];
	return pref[r]-pref[l-1];
}

ll dp(int l, int r) {
	if (l == r) return 0;
	if (memo[l][r] != -1) return memo[l][r];
	ll minn = INF;
	for (int i=l ; i<r ; i++) {
		minn = min(minn, dp(l, i)+dp(i+1, r)+sum(l, r));
	}
	return memo[l][r] = minn;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n;
	scanf("%d", &n);
	for (int i=0 ; i<n ; i++) {
		if (i) pref[i] = pref[i-1];
		scanf("%d", a+i);
		pref[i] += a[i];
	}
	printf("%lld\n", dp(0, n-1));
	return 0;
}