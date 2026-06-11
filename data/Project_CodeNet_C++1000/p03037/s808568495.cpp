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
typedef tuple<double, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	int L = -INF, R = INF;
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		L = max(L, l);
		R = min(R, r);
	}
	cout << max(0, R - L + 1) << endl;
}