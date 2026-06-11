#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const long long infLL = 0x3f3f3f3f3f3f3f3fLL;

int a,b,q;
long long s[maxn],t[maxn];

long long solve(long long x, long long s[], int a) {
	int i = upper_bound(s,s+a,x)-s;
	long long ret = infLL;
	if (i < a) ret = min(ret, s[i]-x);
	if (i > 0) ret = min(ret, x - s[i-1]);
	return ret;
}

long long solve(long long x, long long s[],int a,long long t[],int b) {
	int i = upper_bound(s,s+a,x)-s;
	long long ret = infLL;
	if (i < a) ret = min(ret, s[i]-x+solve(s[i],t,b));
	if (i > 0) ret = min(ret, x - s[i-1]+solve(s[i-1],t,b));
	return ret;
}

int main() {
	scanf("%d%d%d",&a,&b,&q);
	for (int i = 0; i < a; i++) scanf("%lld",&s[i]);
	for (int i = 0; i < b; i++) scanf("%lld",&t[i]);
	for (int i = 0; i < q; i++) {
		long long x;
		scanf("%lld",&x);
		printf("%lld\n",min(solve(x,s,a,t,b),solve(x,t,b,s,a)));
	}
}