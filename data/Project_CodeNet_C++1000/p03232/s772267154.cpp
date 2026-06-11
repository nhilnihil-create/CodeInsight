#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100000;
const int Pt = 1e9 + 7;
int n;
LL a[maxn + 5], rg[maxn + 5];
LL qwe(LL x, LL y) {
	LL t = 1;
	while(y > 0) {
		if(y & 1)t = t * x % Pt;
		y /= 2;
		x = x * x % Pt;
	}
	return t;
}
LL A, B;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; B = (B + rg[i]) % Pt, i++) rg[i] = qwe(i, Pt - 2);
	for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	LL res = 0;
	LL x = 1;
	for(int i = 1; i <= n; i++) {
		if(i > 1)A = (A + rg[i]) % Pt, B = (B - rg[n - i + 2] + Pt) % Pt;
		res = (res + (A + B) % Pt * a[i]) % Pt;
		x = x * i % Pt;
	} 
	printf("%lld\n", res * x % Pt);
	return 0;
}