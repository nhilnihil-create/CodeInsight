#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

int main() {
	ll a, b; cin >> a >> b;
	char m[100][100] = {};
	ll s = 100;

	rep(i, 0, s / 2) {
		rep(j, 0, s) {
			m[i][j] = '#';
		}
	}
	rep(i, s / 2, s) {
		rep(j, 0, s) {
			m[i][j] = '.';
		}
	}
	a--; b--;

	rep(i, 0, s / 2) {
		rep(j, 0, s) {
			if ((i & 1) && (j & 1)) {
				m[i][j] = '.';
				a--;
			}
			if (a == 0)break;
		}
		if (a == 0)break;
	}
	cout << s << " " << s << endl;
	rep(i, s / 2 + 1, s) {
		rep(j, 0, s) {
			if ((i & 1) && (j & 1)) {
				m[i][j] = '#';
				b--;
			}
			if (b == 0)break;
		}
		if (b == 0)break;
	}
	rep(i, 0, s) {
		rep(j, 0, s) {
			cout << m[i][j];
		}
		cout << endl;
	}

	return 0;
}