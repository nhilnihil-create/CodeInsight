#include <cmath>
#include <cstdio>
int main(){
	long long int n, k, p = 1, ans = 1;
	scanf("%lld %lld",&k,&n);
	if (k == 1){
		printf("%lld\n",n);
		return 0;
	}
	while (n > 1 && p <= sqrt(n)){
		p++;
		if (n % p != 0){
			continue;
		}
		long long int c = 0;
		while (n % p == 0){
			n /= p;
			c++;
		}
		ans *= pow(p, c / k);
	}
	printf("%lld\n",ans);
}