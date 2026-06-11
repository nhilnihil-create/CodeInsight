#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
#include <stdio.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = (a); i < (int)(b); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vint;
typedef vector<string> vstr;
typedef pair<ll, ll> pint;
unsigned long long inf = (1LL << 62);
ll mod = 998244353;
pint dx[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll min(ll a, ll b) {
	if (a < b)
		return a;


	return b;
}

ll max(ll a, ll b) {
	if (a < b)
		return b;

	return a;
}


ll N, X;
vector<ll> x;

unsigned long long sum[2 * 100005];

unsigned long long E(int a) {

	if (a == 1) {
		return 5;
	}
	else
		return 2 * a + 1;

}


int main() {

	cin >> N >> X;
	
	x.resize(N+1);
	rep(i, N) {
		cin >> x[i+1];

		sum[i + 1] = sum[i] + x[i+1];
	}

	unsigned long long ans = inf;
	unsigned long long  val = 0;
	for (int k = 1; k <= N; k++) {

		for (int j = 1; j <= N / k; j++) {
			val += E(j) * (sum[N - k * (j - 1)] - sum[N - k * j]);
		}

		if (N % k != 0) {

			val += E(N / k + 1) * (sum[N - k * (N / k)] - sum[0]);
		}

		ans = min(val + k * X + N * X, ans);
		val = 0;
	}

	cout << ans << endl;
	return 0;
}
