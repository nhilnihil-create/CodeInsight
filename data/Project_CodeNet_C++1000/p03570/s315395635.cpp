#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)

using namespace std;

int n, opt;
char s[200010];
int h[1<<26];

int main() {
	int now = 0, i, j;
	scanf("%s", s+1); n = strlen(s+1);
	memset(h, 0x3f, sizeof h); h[0] = 0;
	rep(i, 1, n) {
		now ^= 1 << s[i] - 'a';
		opt = h[now];
		for(j = 0; j < 26; ++j) opt = min(opt, h[now^(1<<j)]);
		++opt;
		//printf("%d %d\n", i, opt);
		h[now] = min(h[now], opt);
	}
	printf("%d\n", opt);
	return 0;
}