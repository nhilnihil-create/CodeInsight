#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

static const ULL M = 1000000007;

struct RMQ {
	UL N;
	vector<ULL> V;
	RMQ(UL n) {
		N = 1; while (N < n) N <<= 1;
		V.resize(N * 2 - 1);
	}
	ULL query(UL l, UL r, UL a = ~0u, UL b = ~0u, UL i = ~0u) {
		if (a == ~0u) { a = 0; b = N; i = 0; }
		if (r <= a || b <= l) return 0;
		if (l <= a && b <= r) return V[i];
		return max(query(l, r, a, (a + b) >> 1, (i << 1) + 1),
			query(l, r, (a + b) >> 1, b, (i << 1) + 2));
	}
	void upd(UL p, ULL v) {
		UL i = p + N - 1;
		V[i] = v;
		while (i != 0) {
			i = (i - 1) >> 1;
			V[i] = max(V[(i << 1) + 1], V[(i << 1) + 2]);
		}
	}
};

struct Problem {
public:

	UL N;
	UL H[200000];
	ULL dp[200000];

	void Solve() {
		scanf("%u", &N);
		rep(i, N) { scanf("%u", &H[i]); H[i]--; }
		RMQ Q(N);
		rep(i, N) {
			ULL A;
			scanf("%llu", &A);
			dp[i] = A + Q.query(0, H[i] + 1);
			Q.upd(H[i], dp[i]);
		}
		printf("%llu", Q.query(0, N));
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
