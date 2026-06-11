#include <iostream>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
static const double PI = 3.1415926535897932384626433;
static const ll LL_MAX = (ll)1 << 62;
static const ll MOD = 1000000007;

char A[100][100] = {};

int main() {
	ll a, b; cin >> a >> b;
	ll S = 100;
	rep(i, 0, S) {
		rep(j, 0, S) {
			if (i > S / 2) {
				A[i][j] = '#';
			}
			else {
				A[i][j] = '.';
			}
		}
	}
	a--; b--;
	rep(i, 0, S / 2 + 1) {
		if (!b)break;
		rep(j, 0, S) {
			if (!b)break;
			if (j % 2 == 0 && i % 2 == 0) {
				A[i][j] = '#';
				b--;
			}
		}
	}

	rep(i, S / 2 + 1, S) {
		if (!a)break;
		rep(j, 0, S) {
			if (!a)break;
			if (j % 2 == 0 && i % 2 == 0) {
				A[i][j] = '.';
				a--;
			}
		}
	}
	cout << 100 << " " << 100 << endl;
	rep(i, 0, S) {
		rep(j, 0, S) {
			cout << A[i][j];
		}
		cout << endl;
	}

	return 0;
}