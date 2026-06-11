#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;


ll V[51];
ll l[51], r[51];
ll ans = -1e9;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll N, K;
	cin >> N >> K;

	FOR(i, 0, N) {
		cin >> V[i];
	}
	l[0] = V[0];
	r[N - 1] = V[N - 1];

	FOR(i, 1, N) {
		l[i] = l[i - 1] + V[i];
		r[N - 1 - i] = r[N - i] + V[N - 1 - i];
	}
	

	for (int i=0; i <= min(N,K); i++) {
		for (int j = 0; i + j <= min(N,K); j++) {
			ll cur = 0;
			priority_queue<ll> que;
			FOR(k, 0, i) {
				if (i >= N - 1)break;
				cur += V[k];
				que.push(-V[k]);
			}
			FOR(s, 0, j) {
				if (N - 1 - s < 0)break;
				cur += V[N - 1 - s];
				que.push(-V[N - 1 - s]);
			}
			FOR(t, 0, max(0LL, K - i-j)) {
				if (que.empty())break;
				if (que.top() <= 0)break;
				cur += que.top();
				que.pop();
			}
			ans = max(ans, cur);
		}
	}

	cout << ans << endl;


	return 0;
}