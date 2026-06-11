#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
ll A[1 << 18];

void upd(pll &a, pll b) {
	pll r;
	if (a.first > b.first) r = pll(a.first, max(b.first, a.second));
	else r = pll(b.first, max(b.second, a.first));
	a = r;
}

pll B[1 << 18];
ll C[1 << 18];

int main() {
	scanf("%d", &N);
	rep(i, 1 << N) scanf("%lld", A + i);
	reverse(A, A + (1 << N));
	int M = 1 << N;
	rep(i, M) B[i] = pll(A[i], -1e18);
	for (int i = 0; i < N; i++) {
		rep(j, M) {
			int c = !!(1 << i & j);
			if (c == 0) upd(B[j], B[j + (1 << i)]);
		}
	}
	rep(i, M - 1) {
		C[i] = B[i].first + B[i].second;
	}
	reverse(C, C + M);
	ll ans = C[0];
	for (int i = 1; i < M; i++) {
		ans = max(ans, C[i]);
		printf("%lld\n", ans);
	}
	return 0;
}