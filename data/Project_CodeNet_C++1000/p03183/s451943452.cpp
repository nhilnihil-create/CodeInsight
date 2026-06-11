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
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
t3 p[1010];
ll dp[1010][10010];

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		int w, s, v; scanf("%d%d%d", &w, &s, &v);
		p[i] = t3(w, s, v);
	}
	sort(p+1, p+1+N, [](t3 a, t3 b) { return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b);} );
	rep(i, 1010) rep(j, 10010) dp[i][j] = -1e18;
	dp[0][0] = 0;
	for(int i=1;i<=N;i++) {
		int w, s, v;
		tie(w, s, v) = p[i];
		for(int j=0;j<=10001;j++) {
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(s >= j) dp[i][min(j+w, 10001)] = max(dp[i][min(j+w, 10001)], dp[i-1][j] + v);
		}
	}
	ll ans = -1e18;
	for(int i=0;i<=10001;i++) ans = max(ans, dp[N][i]);
	printf("%lld\n", ans);
	return 0;
}
