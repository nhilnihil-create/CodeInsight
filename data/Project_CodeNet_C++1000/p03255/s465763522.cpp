#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200018;
const ll oo = 9e18;

ll x[N];
ll X;
int n;

ll mul(ll a, ll b){
	return a > oo / b ? oo : a * b;
}

ll add(ll a, ll b){
	return a > oo - b ? oo : a + b;
}
int main(){

	scanf("%d %lld", &n, &X);

	for(int i = 1; i <= n; i++) scanf("%lld", x+i);
	reverse(x+1,1 + x + n);
	ll psum[N];
	partial_sum(x+1, x + 1 + n, psum+1);
	
	ll ans = 1e18;
	for(int k = 1; k <= n; k++){
		int j = 1;
		ll sum = 0;
		int i;
		for(i = k; i <= n; i += k){
			if(j == 1)
				sum = add(sum, (psum[i] - psum[i - k]) * 5);
			else
				sum = add(sum, mul(psum[i] - psum[i - k] , (2*j + 1)));
			j++;
		}
		if(i - k < n){
			sum = add(sum, mul(psum[n] - psum[i - k] , (2*j + 1)));
		}
		ans = min(ans, sum + k * X);
	}
	printf("%lld\n", ans + X * n);
}
