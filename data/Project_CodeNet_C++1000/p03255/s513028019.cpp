#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<cctype>
#include<set>
#include<vector>
#include<queue>
#include<map>
#define fi(s) freopen(s,"r",stdin);
#define fo(s) freopen(s,"w",stdout);
using namespace std;
typedef long long LL;

inline LL read() {
    LL x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

LL a[200005];

int main() {
	int n = read();LL x = read();
	for (int i=1; i<=n; ++i) a[i] = read() + a[i - 1];
	LL ans = 1e18;
	for (int k=1; k<=n; ++k) {
		LL sum = 0, now = 3;
		for (int i=n; i>=1; i-=k) {
			sum += (a[i] - a[max(0, i - k)]) * max(now, 5ll), now += 2;
			if (sum >= ans) break;
		}
		ans = min(ans, sum + 1ll * (k + n) * x);
	}
	cout << ans;
	return 0;
}