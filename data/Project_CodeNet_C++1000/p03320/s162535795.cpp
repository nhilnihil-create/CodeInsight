#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int s(ll x) {
	if(!x) return 0;
	return x%10+s(x/10);
}
int main() {
	int K;
	scanf("%d",&K);
	ll n=1,d=1;
	printf("%d\n",1); K--;
	while(K--) {
		if(s(n+10*d)*(n+d)>(n+10*d)*s(n+d)) d*=10;
		printf("%lld\n",n+=d);
	}
}