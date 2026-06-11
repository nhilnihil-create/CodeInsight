#include<cstdio>
#include<algorithm>
using namespace std;
long long S[201000];
int n;
int Go(int b, int e) {
	int bb = b, ee = e, mid, r = b;
	while (bb <= ee) {
		mid = (bb + ee) >> 1;
		if ((S[mid] - S[b]) * 2 <= S[e] - S[b]) {
			r = mid;
			bb = mid + 1;
		}
		else ee = mid - 1;
	}
	return r;
}
long long w[4], res = 1e18;
void Calc(int p1, int p2, int p3) {
	w[0] = S[p1];
	w[1] = S[p2] - S[p1];
	w[2] = S[p3] - S[p2];
	w[3] = S[n] - S[p3];
	sort(w, w + 4);
	res = min(res, w[3] - w[0]);
}
int main() {
	int i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		S[i] = S[i - 1] + a;
	}
	for (i = 1; i < n; i++) {
		int p1 = Go(0, i);
		int p2 = Go(i, n);
		Calc(p1, i, p2);
		Calc(p1, i, p2 + 1);
		Calc(p1 + 1, i, p2);
		Calc(p1 + 1, i, p2 + 1);
	}
	printf("%lld\n", res);
}