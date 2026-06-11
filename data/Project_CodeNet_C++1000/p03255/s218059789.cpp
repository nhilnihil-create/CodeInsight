#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const long long MOD = 1e9 + 7;
const long long  INF = 5e18;
const double DINF = 5e14;
const double eps = 1e-10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()



ull n, X, x[200010], rui[200010], ans = INF;

int main() {
	cin >> n >> X;
	for (int i = 0;i < n;i++) {
		cin >> x[i];
		rui[i + 1] = rui[i] + x[i];
	}
	for (int k = 1;k <= n;k++) {
		ull sum = n * X + k * X, p = 5;
		for (int now = n;now > 0;) {
			if (now == n)sum += (rui[now] - rui[max(0, now - 2 * k)])*p, now -= 2 * k, now = max(now, 0), p += 2;
			else sum += (rui[now] - rui[max(0, now - k)])*p, p+=2, now -= k, now = max(now, 0);
		}
		if (sum < 0)continue;
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}

