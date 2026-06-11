#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D[202020], K[202020], C[202020];
ll n;

bool check(ll k)
{
	ll i, x, cnt;
	
	for(i=0; i<=n+n+1; i++) K[i] = C[i] = 0;
	
	cnt = 0;
	x = n + 1; K[x] ++, C[x] ++;
	
	for(i=1; i<=n; i++){
		if(D[i] < k) x -= 1;
		else x += 1;
		cnt += C[x - 1] + K[x];
		K[x] ++; C[x] = C[x - 1] + K[x];
	}
	
	return cnt * 4 >= n * (n + 1);
}

int main()
{
	ll i, s, e, mid;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++){
		scanf("%lld", D + i);
	}
	
	for(s=1, e=1e9; s<=e; ){
		mid = s + e >> 1;
		if(check(mid)) s = mid + 1;
		else e = mid - 1;
	}

	check(1);
	
	printf("%lld\n", s - 1);
	
	return 0;
}