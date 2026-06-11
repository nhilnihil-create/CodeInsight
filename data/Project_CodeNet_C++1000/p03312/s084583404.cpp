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
ll S[200020];
int cut_l[200020], cut_r[200020];

ll ans = 1e18;
void Do(int a, int b, int c) {
	if (a == b || b == c) return;
	if (a == 0 || c == N) return;
	ll v[4] = { S[a], S[b] - S[a], S[c] - S[b], S[N] - S[c] };
	sort(v, v + 4);
	ans = min(ans, v[3] - v[0]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		S[i] = S[i - 1] + x;
	}
	for (int i = 1, j = 0; i <= N; i++) {
		while (S[j] * 2 < S[i]) ++j;
		cut_l[i] = j;
	}
	for (int i = N, j = N; i; i--) {
		while ((S[N] - S[j]) * 2 < (S[N] - S[i])) --j;
		cut_r[i] = j;
	}
	for (int i = 2; i <= N - 2; i++) {
		int li = cut_l[i];
		int ri = cut_r[i];
		for (int l : {li - 1, li}) for (int r : {ri, ri + 1}) {
			Do(l, i, r);
		}
	}
	printf("%lld\n", ans);
	return 0;
}