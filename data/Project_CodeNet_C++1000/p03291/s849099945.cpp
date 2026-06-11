#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

char str[N];
int n, pw[N] = {1}, pre[N], suf[N], p[N], s[N];

int main() {
	scanf("%s", str + 1);
	for(int i = 1; i <= 1000; i ++) i = i - 1 + 1;
	n = strlen(str + 1);
	for(int i = 1; i <= n; i ++) { pw[i] = pw[i - 1] * 3ll % mo; }
	for(int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + (str[i] == 'A');
		p[i] = p[i - 1] + (str[i] == '?');
	}
	for(int i = n; i >= 1; i --) {
		suf[i] = suf[i + 1] + (str[i] == 'C');
		s[i] = s[i + 1] + (str[i] == '?');
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(str[i] == 'B') {
			(ans += 1ll * pre[i - 1] * suf[i + 1] % mo * pw[p[n]] % mo) %= mo;
			if(p[i]) (ans += 1ll * p[i] % mo * suf[i + 1] % mo * pw[p[n] - 1] % mo) %= mo;
			if(s[i]) (ans += 1ll * s[i] % mo * pre[i - 1] % mo * pw[p[n] - 1] % mo) %= mo;
			if(p[i] && s[i])
				(ans += 1ll * s[i] * p[i] % mo * pw[p[n] - 2] % mo) %= mo;
		} else if(str[i] == '?') {
			(ans += 1ll * pre[i - 1] * suf[i + 1] % mo * pw[p[n] - 1] % mo) %= mo;
			if(p[i - 1]) (ans += 1ll * p[i - 1] % mo * suf[i + 1] % mo * pw[p[n] - 2] % mo) %= mo;
			if(s[i + 1]) (ans += 1ll * s[i + 1] % mo * pre[i - 1] % mo * pw[p[n] - 2] % mo) %= mo;
			if(p[i - 1] && s[i + 1])
				(ans += 1ll * s[i + 1] * p[i - 1] % mo * pw[p[n] - 3] % mo) %= mo;
		}
	}
	printf("%d", ans);
	return 0;
}
//AtCoder - 4232
