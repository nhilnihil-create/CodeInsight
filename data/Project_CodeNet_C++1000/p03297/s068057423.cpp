#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

long long gcd(long long x, long long y) {
	if (x < 0)x = -x;
	if (y < 0)y = -y;
	if (x > y)swap(x, y);
	if (x == 0)return y;
	if (y%x == 0)return x;
	return gcd(y%x, x);
}

int main() {
	int n;
	long long a, b, c, d, g, x;
	scanf("%d", &n);
	f(i, n) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a < b) {
			printf("No\n");
			continue;
		}
		if (d < b) {
			printf("No\n");
			continue;
		}
		g = gcd(b, d);
		x = a % g;
		x = (c - x + g) / g;
		x = x * g;
		x += (a%g);
		if(x<b)printf("No\n");
		else printf("Yes\n");
	}


	return 0;
}