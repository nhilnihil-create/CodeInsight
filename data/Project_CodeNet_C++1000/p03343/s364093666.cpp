#include <bits/stdc++.h>
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 2055;

struct BIT {
	int d[MAXN];
	void upd(int x, int r) {
		for(x += 5; x < MAXN; x += rb(x))
			d[x] += r;
	}
	int get(int x) {
		int r = 0; for(x += 5; x; x -= rb(x))
			r += d[x];
		return r;
	}
	int get(int s, int e) { return s <= e ? get(e) - get(s-1) : 0; }
} bit;

set<pii> PQ;

int A[MAXN], O[MAXN];

int N, K, Q, Ans = INF, Sum;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++) cin >> A[i];
	iota(O, O+N+1, 0); sort(O+1, O+N+1, [&](int a, int b) {
		return A[a] < A[b];
	});

	PQ.insert(pii(1, N));
	for(int s = 1, e = 1; s <= N; s++) {
		for(; Sum < Q && e <= N; e++) {
			int i = O[e];
			auto it = prev(PQ.lower_bound(pii(i, INF)));
			int p, q; tie(p, q) = *it;

			Sum -= max(0, min(bit.get(p, q), q-p+2-K));
			bit.upd(i, 1);
			Sum += max(0, min(bit.get(p, q), q-p+2-K));
		}
		if(Sum < Q) break;
		int t = A[O[e-1]] - A[O[s]];
		if(t < Ans) Ans = t;

		int i = O[s];
		auto it = prev(PQ.lower_bound(pii(i, INF)));
		int p, q; tie(p, q) = *it;
		PQ.erase(it);

		Sum -= max(0, min(bit.get(p, q), q-p+2-K));
		bit.upd(i, -1);

		if(p < i) {
			PQ.insert(pii(p, i-1));
			Sum += max(0, min(bit.get(p, i-1), i-p+1-K));
		}
		if(i < q) {
			PQ.insert(pii(i+1, q));
			Sum += max(0, min(bit.get(i+1, q), q-i+1-K));
		}
	}

	cout << Ans << endl;
	return 0;
}