#pragma GCC target("avx")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

int_fast32_t n, h, w, a, b, ans;
int main(){
	scanf("%ld %ld %ld", &n, &h, &w);
	while(n--){
		scanf("%ld %ld", &a, &b);
		ans += (a>=h && b>=w);
	}
	printf("%ld\n", ans);
	return 0;
}
