#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int m, k;
	cin >> m >> k;

	if (k >= (1 << m))cout << -1 << endl;
	else if (m <= 1) {
		if (k)cout << -1 << endl;
		else if (m)cout << "0 1 1 0" << endl;
		else cout << "0 0" << endl;
	}
	else {
		rep(i, 1 << m)if (i != k)cout << i << " ";
		cout << k << " ";
		rep(i, 1 << m)if ((1 << m) - i - 1 != k)cout << (1 << m) - i - 1 << " ";
		cout << k << endl;
	}
}