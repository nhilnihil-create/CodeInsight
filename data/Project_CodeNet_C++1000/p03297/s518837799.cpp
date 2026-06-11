#include <bits/stdc++.h>
using namespace std;

int t;
long long a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		
		if(a < b || d < b){
			printf("No\n");
			continue;
		}
		if(c + 1 >= b){
			printf("Yes\n");
			continue;
		}
		
		d = __gcd(d, b);
		a %= d;
		
		if(a > c){
			printf("No\n");
			continue;
		}
		
		long long y = (a + (c - a + d) / d * d) % b;
		
		if(y <= c)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

