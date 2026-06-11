#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000], n, S[101000], BIT[201000];
void Add(int a, int b) {
	while (a <= n + n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
bool Pos(int K) {
	int i;
	for (i = 1; i <= n; i++) {
		S[i] = S[i - 1];
		if (w[i] >= K)S[i]++;
		else S[i]--;
	}
	for (i = 0; i <= n + n; i++)BIT[i] = 0;
	long long res = 0;
	for (i = 0; i <= n; i++) {
		res += Sum(S[i] + n);
		if (i == n)break;
		Add(S[i] + n, 1);
	}
	if (res * 2 >= 1ll * n*(n + 1) / 2)return true;
	return false;
}
int main() {
	int i, b = 1, e = 1e9, r = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	while (b <= e) {
		int mid = (b + e) >> 1;
		if (Pos(mid)) {
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	printf("%d\n", r);
}