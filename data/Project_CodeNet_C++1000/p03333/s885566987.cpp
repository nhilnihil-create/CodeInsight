#include <bits/stdc++.h>
#define MAXN 100005
#define LL long long 
using namespace std;

LL n, ans, l[MAXN], r[MAXN];

bool CMP1(LL x, LL y) {return x>y;}
bool CMP2(LL x, LL y) {return x<y;}

int main()
{
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld%lld", &l[i], &r[i]);
	sort(l, l+n+1, CMP1);
	sort(r, r+n+1, CMP2);
	for(int i=0; i<=n; i++) if(l[i]>r[i]) ans+=l[i]-r[i];
	printf("%lld\n", ans*2);
} 