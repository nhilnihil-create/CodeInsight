#include<bits/stdc++.h>
using namespace std;
int n, k;
long long s[600000], ans, *f = s, *b = s, *t = s, u;
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%lld", b);
		t = b++;
		while(f != t) *b++ = *t + *f++;
	}
	for(u = 1LL<<40, f = s; u; u /= 2){
		sort(f, b);
		t = lower_bound(f, b, u);
		if(b-t >= k){
			ans += u;
			f = t;
		}
		while(t != b) *t++ ^= u;
	}
	printf("%lld\n", ans);
}