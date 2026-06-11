#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, p[maxn], t;
char s[maxn];
long long ans;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int j;
	for (int i = 1; i <= n; i = j + 1) {
		t = 0;
		for (j = i; j <= n; ) {
			if(s[j] == 'A') {
				p[++t] = 1;
				++j;
				continue;
			}
			if(s[j] == 'B' && j < n && s[j + 1] == 'C') {
				p[++t] = 2;
				j += 2;
				continue;
			}
			break;
		}
		long long now = 0;
		for (int k = 1; k <= t; ++k) {
			if(p[k] == 1) ++now;
			else ans += now;
		}
	} 
	printf("%lld\n", ans);
	return 0;
}