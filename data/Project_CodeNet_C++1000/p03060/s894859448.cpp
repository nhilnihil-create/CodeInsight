#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	vector<int> c(n), v(n);
	rep(i, n) cin >> v[i];
	rep(i, n) cin >> c[i];
	int ans = 0;
	for (int bit = 0; bit < (1 << n); bit++) {
		int cos = 0;
		int val = 0;
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				cos += c[i];
				val += v[i];
			}
		}
		ans = max(ans, val - cos);
	}
	pf(ans);

	return 0;
}