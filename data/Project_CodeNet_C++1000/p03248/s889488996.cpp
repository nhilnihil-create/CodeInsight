#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int n, fa[N];
char s[N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	s[0] = '0';
	if(s[1] == '0') { puts("-1"); return 0; }
	for(int i = 1; i <= n; i ++) 
		if(s[i] != s[n - i]) {
			puts("-1"); return 0;
		}
	int sz = 1, p = n; s[n] = '1';
	for(int i = 2; i <= n; i ++) {
		if(s[i] == '1') {
			int o = i - sz - 1, f = p - o - 1;
			for(; p != f; p --) fa[p] = f;
			sz = i;
		}
	}
	for(int i = 1; i <= n; i ++) if(fa[i])
		printf("%d %d\n", i, fa[i]);
	return 0;
}
