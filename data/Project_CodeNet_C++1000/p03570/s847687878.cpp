#include <cstdio>
#include <map>
#include <vector>
using namespace std;
char s[200010];
map<int, int> dp;
map<int, int> f;
void upd(int v, int t) {
	if (!dp.count(v) || dp[v] > t) {
		dp[v] = t;
	}
}
int main() {
	int l;
	scanf("%s", s);
	for (l = 0; s[l]; l++) ;
	int b = 0;
	for (int i = 0; i < l; i++) {
		int x = s[i] - 'a';
		f[b]++;
		b ^= 1 << x;
	}
	f[b]++;
	b = 0;
	for (int i = 0; i < l; i++) {
		int r = i == 0 ? 0 : dp[b];
		f[b]--;
		if (f[b]) {
			upd(b, r + 1);
		}
		for (int j = 0; j < 26; j++) {
			int y = b ^ (1 << j);
			if (f[y]) {
				upd(y, r + 1);
			}
		}
		int x = s[i] - 'a';
		b ^= 1 << x;
	}
	printf("%d\n", dp[b]);
	return 0;
}
