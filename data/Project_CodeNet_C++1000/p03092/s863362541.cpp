#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL N = 1000000007;

LL n,l,r;
LL a[5005],dp[5005];

struct BIT{
	LL tr[100005];
	LL lowbit(LL x){ return (x & (-(x))); }
	void modify(LL x,LL v){ for(;x <= n + 2;x += lowbit(x)); tr[x] += v; }
	LL query(LL x){ LL ret = 0; for(;x;x -= lowbit(x)) ret += tr[x]; return ret; }
}t;

int main(){
	memset(dp,0x3f,sizeof(dp));
	cin >> n >> r >> l;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i];
		a[i] ++;
	}
	a[0] = 1; dp[0] = 0; a[n + 1] = n + 2;
	for(LL i = 1;i <= n + 1;i ++){
		LL sr = 0,sl = 0;
//		dp[i] = dp[i - 1] + l;
		for(LL j = i - 1;j >= 0;j --){
			if(a[j] < a[i]) dp[i] = min(dp[i],dp[j] + r * sr + l * sl);
			if(a[j] > a[i]) sr ++; if(a[j] < a[i]) sl ++;
			t.modify(a[j],1);
//			cout << i << ' ' << j << ' ' << sr << ' ' << dp[i] << endl;
		}
		for(LL j = i - 1;j >= 0;j --) t.modify(a[j],-1);
	}
	cout << dp[n + 1] << endl;
	return 0;
}