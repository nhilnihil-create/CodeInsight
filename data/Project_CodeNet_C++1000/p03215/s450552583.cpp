#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, K, a[1005], topp = 0;
ll val[1000005], cur = 0, ans = 0;

int main(){
	getint(N), getint(K);
	for(register int i = 1; i <= N; i++) getint(a[i]);
	for(register int i = 1; i <= N; i++, cur = 0)
		for(register int j = i; j <= N; j++) val[++topp] = cur += a[j];
	for(register int ex = 39; ex >= 0; ex--){
		register int cnt = 0;
		for(register int i = 1; i <= topp; i++) if(val[i] & (1LL << ex)) cnt++;
		if(cnt < K) continue; ans += 1LL << ex, cnt = 0;
		for(register int i = 1; i <= topp; i++) if(val[i] & (1LL << ex)) val[++cnt] = val[i];
		topp = cnt;
	}
	return printf("%lld\n", ans), 0;
}