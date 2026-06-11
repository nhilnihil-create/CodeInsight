#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int q;
LL a, b;
int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%lld%lld", &a, &b);
		LL n = a * b;
		LL temp = sqrt(n);
		LL res = temp * 2LL;
		if(temp * temp == n) {
			res -= 2LL;
		}
		else if(temp * (temp + 1LL) >= n)res--;
		if(a != b)res--;
		printf("%lld\n", res);
	}
	return 0;
}