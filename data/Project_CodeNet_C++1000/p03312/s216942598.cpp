#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 200003;
int n;
LL s[N], ans = 1e18;
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++) scanf("%lld", s + i), s[i] += s[i - 1];
	for(Rint b = 2;b <= n - 2;b ++){
		int a = lower_bound(s + 1, s + b, s[b] >> 1) - s;
		if(a == b) -- a;
		if(a > 2 && abs(s[b] - s[a] * 2) > abs(s[b] - s[a - 1] * 2)) -- a;
		int c = lower_bound(s + b + 1, s + n, (s[n] + s[b]) >> 1) - s;
		if(c == n) -- c;
		if(c > b + 1 && abs(s[n] + s[b] - s[c] * 2) > abs(s[n] + s[b] - s[c - 1] * 2)) -- c;
		ans = min(ans, max(s[a], max(s[b] - s[a], max(s[c] - s[b], s[n] - s[c]))) - min(s[a], min(s[b] - s[a], min(s[c] - s[b], s[n] - s[c]))));
	}
	printf("%lld", ans);
}