#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 5005
using namespace std;

typedef long long ll;

ll n, A, B, a[N], yer[N], dp[N][N];

ll f(ll ind, ll x){
	ll &r = dp[ind][x];
	if(r != -1)
		return r;
	if(ind == n + 1)
		return 0;
	ll ek = (yer[ind] > x)? B : (yer[ind] < x) ? A : 0;
	r = f(ind + 1, x) + ek;
	if(yer[ind] > x)
		r = min(r, f(ind + 1, yer[ind]));
	// cout << ind << " " << x << " = " << r << endl;
	return r;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	memset(dp, -1, sizeof dp);

	scanf("%lld %lld %lld",&n ,&A ,&B);

	for(ll i = 1; i <= n; i++){
		scanf("%lld",a + i);
		yer[a[i]] = i;
	}

	printf("%lld\n", f(1, 0));
	return 0;
}