#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main()
{
	LL n,p;
	scanf("%lld%lld",&n,&p);
	LL cnt = 0,s = 1;
	if (n == 1) {
		printf("%lld\n",p);
		return 0;
	}
	for (LL i = 2; i <= sqrt(p); i++){
		while (p % i == 0){
			cnt++;
			p /= i;
			if (cnt >= n){
				s *= i;
				cnt = 0;
			}
		}
		cnt = 0;
	}
	printf("%lld\n",s);
}