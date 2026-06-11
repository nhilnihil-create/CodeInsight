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

int N, A[200020], B[200020];

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A + i);
	for(int i=1;i<=N;i++) scanf("%d", B + i);
	ll ans = 0;
	for(int i=28;i>=0;i--) {
		vector <int> va, vb;
		for(int j=1;j<=N;j++) va.pb(A[j] & ((1<<(i+1))-1));
		for(int j=1;j<=N;j++) vb.pb(B[j] & ((1<<(i+1))-1));
		sort(all(va));
		sort(all(vb));
		ll cnt[3] = {}, L = 1<<i;
		for(int a=0, b=N-1;a<N;a++) {
			while(b >= 0 && va[a] + vb[b] >= L) --b;
			cnt[0] += b + 1;
		}
		for(int a=0, b=N-1;a<N;a++) {
			while(b >= 0 && va[a] + vb[b] >= 2*L) --b;
			cnt[1] += b + 1;
		}
		for(int a=0, b=N-1;a<N;a++) {
			while(b >= 0 && va[a] + vb[b] >= 3*L) --b;
			cnt[2] += b + 1;
		}
		ll c = (ll)N*N - cnt[2] + cnt[1] - cnt[0];
		if(c & 1) ans += L;
	}
	printf("%lld\n", ans);
	return 0;
}
