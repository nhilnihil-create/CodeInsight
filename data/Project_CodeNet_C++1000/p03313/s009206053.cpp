#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109311;
const long double pi = 3.1415926535897932384626433;
typedef pair<int, int> P;
typedef pair<int, P> PP;
struct edge { int to, cost; };
int a[1000000];
int zeta[400000],zeta2[400000];
int sum[400000];
signed main() {
	int n; cin >> n;
	rep(i, 1ll << n)cin >> a[i];
	rep(i, 1 << n)zeta[i] = a[i];

	rep(i, n) {
		rep(j, 1 << n) {
			if ((j&(1 << i))) {
				int b[4];
				b[0] = zeta[j], b[1] = zeta[j ^ (1 << i)], b[2] = zeta2[j], b[3] = zeta2[j ^ (1 << i)];
				sort(b, b + 4);
				zeta[j] = b[3]; zeta2[j] = b[2];
			}
		}
	}
	rep(i, 1 << n) {
		sum[i] = zeta[i] + zeta2[i];
	}
	rep(i, 1 << n)sum[i + 1] = max(sum[i], sum[i + 1]);
	for (int i = 1; i < (1 << n); i++)cout << sum[i] << endl;
}