#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;

ll n, x, s, mn=2e18, a[200005];
int main() {
	ll i, j, k;
	scanf("%lld%lld", &n, &x);
	for(i=1; i<=n; i++) scanf("%lld", &a[i]), a[i] += a[i-1];
	for(int i=1;i<=n;i++){
		k = 2;
		s = (n+i)*x;
		int id = n;
		while(id>0){
			s += (2*k+1)*(a[id]-a[max(id-i,0)]);
			if(id!=n) k++;
			id -= i;
		}
		mn = min(mn, s);
	}
	printf("%lld", mn);
	return 0;
}