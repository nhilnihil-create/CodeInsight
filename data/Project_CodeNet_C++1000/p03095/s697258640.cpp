#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 7, maxm = 31;
int n;
long long cnt[maxm], ans;
char s[maxn];

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'];
	ans = 1;
	for (int i = 0; i < 26; ++i) ans = ans * (cnt[i] + 1) % mod;
	ans = (ans + mod - 1) % mod;
	printf("%lld\n", ans);
	return 0;
}