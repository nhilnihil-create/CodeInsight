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
#include <time.h>
#include <limits.h>

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

ll X[1010], Y[1010];

int main() {
	int N; scanf("%d", &N);
	for(int i=0;i<N;i++) scanf("%lld%lld", X+i, Y+i);
	for(int i=1;i<N;i++) {
		ll t = (X[i] + Y[i] - X[0] - Y[0]) & 1;
		if(t) {
			puts("-1");
			return 0;
		}
	}
	ll t = (X[0] + Y[0]) & 1;
	int R = 34;
	if(!t) {
		printf("%d\n", R + 1);
		for(int i=0;i<R;i++) printf("%lld ", 1LL<<i); puts("1");
	}
	else {
		printf("%d\n", R);
		for(int i=0;i<R;i++) printf("%lld ", 1LL<<i); puts("");
	}
	for(int i=0;i<N;i++) {
		if(!t) ++X[i];
		ll a = (X[i] + Y[i] + (1LL << R) - 1) / 2;
		ll b = (X[i] - Y[i] + (1LL << R) - 1) / 2;
		for(int j=0;j<R;j++) {
			int ta = !!(1LL << j & a);
			int tb = !!(1LL << j & b);
			printf("%c", "LDUR"[ta*2+tb]);
		}
		if(!t) puts("L");
		else puts("");
	}
	return 0;
}
