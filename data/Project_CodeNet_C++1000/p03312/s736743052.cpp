#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[200005], cum[200005];

ll sum(int l, int r){ return cum[r] - cum[l - 1]; }
ll calc(ll A, ll B, ll C, ll D){
	return max({A, B, C, D}) - min({A, B, C, D});
}

int main()
{
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		cum[i] = cum[i - 1] + a[i];
	}

	ll A = a[1], B = a[2], C = a[3], D = cum[N] - cum[3];
	int le = 1, rs = 4;
	while(rs < N && C + a[rs] < D - a[rs]){
		C += a[rs]; D -= a[rs]; rs++;
	}
	
	ll ans = calc(A, B, C, D);
	if(rs < N) ans = min(ans, calc(A, B, C + a[rs], D - a[rs]));

	for(int mid = 3; mid < N - 1; mid++){
		B += a[mid]; C -= a[mid];
		while(le < mid - 1 && A + a[le + 1] < B - a[le + 1]){
			A += a[le + 1]; B -= a[le + 1]; le++;
		}
		while(rs < N && C + a[rs] < D - a[rs]){
			C += a[rs]; D -= a[rs]; rs++;
		}
		ans = min(ans, calc(A, B, C, D));
		if(le < mid) ans = min(ans, calc(A + a[le + 1], B - a[le + 1], C, D));
		if(rs < N) ans = min(ans, calc(A, B, C + a[rs], D - a[rs]));
		if(le < mid && rs < N) ans = min(ans, calc(A + a[le + 1], B - a[le + 1], C + a[rs], D - a[rs]));
	}
	printf("%lld\n", ans);

	return 0;
}