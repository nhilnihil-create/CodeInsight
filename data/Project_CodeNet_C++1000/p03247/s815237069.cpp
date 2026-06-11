#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
int n,x[1010],y[1010],s[2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", x + i, y + i);
		s[(x[i] + y[i]) & 1]++;
	}
	if (s[0] && s[1]) {
		puts("-1");
		return 0;
	}
	for (int i = 34; i >= 0; i--) v.push_back(1LL << i);
		int t = s[0] ? 5 : 4;
		for (int i = 0; i < t; i++) v.push_back(1);
	printf("%d\n", v.size());
	for (auto &it : v) printf("%lld ", it);
	puts("");
	for (int i = 0; i < n; i++) {
		long long tx=0, ty=0;
		for(auto &it:v) {
			long long dx = x[i]-tx, dy = y[i]-ty;
			if (abs(dx) > abs(dy)) {
				if (dx > 0) {
					putchar('R');
					tx += it;
				}
				else {
					putchar('L');
					tx -= it;
				}
			}
			else {
				if (dy > 0) {
					putchar('U');
					ty += it;
				}
				else {
					putchar('D');
					ty -= it;
				}
			}
		}
		puts("");
	}
	return 0;
}