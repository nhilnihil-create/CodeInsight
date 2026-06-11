#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;

int n;
char s[100005];
int cnt[26];

int main() {
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
	int ans = 1;
	for (int i = 0; i < 26; ++i) ans = 1LL * ans * (cnt[i] + 1) % mod;
	printf("%d\n", (ans - 1 + mod) % mod);
}