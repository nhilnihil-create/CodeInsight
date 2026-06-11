#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n, k;
	cin >> n >> k;

	double ans = 0;
	rep_lr(i, 1, n + 1) {
		double p = 1.0 / n;

		int m = 0;
		ll ii = i;
		while (ii < k) {
			m++;
			ii *= 2;
		}

		p *= pow(0.5, m);
		ans += p;
	}

	cout << fixed << setprecision(12);
	cout << ans << endl;

}