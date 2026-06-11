#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll N, X;
vector<ll> x(200010, 0);
vector<ll> v(200010, 0);

int main(void){
	
	scanf("%lld %lld", &N, &X);
	for(int i = 1; i <= N; ++i) scanf("%lld", &x[i]);
	
	ll sum = 0;
	for(int i = 1; i <= N; ++i) sum += x[i], v[i] = sum;
	
	ll ans = LLONG_MAX;
	for(int k = 1; k <= N; ++k){
	    ll sum = 0;
	    for(int i = 0; i < (N - 1) / k + 1; ++i){
	        ll M = N - i * k;
            ll m = max(0LL, M - k);
            ll c = (i == 0) ? 5 : 2 * i + 3;
            sum += c * (v[M] - v[m]);
            if(sum < 0) break;
	    }
	    sum += N * X + k * X;
	    if(sum > 0) ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	
    return 0;
}
