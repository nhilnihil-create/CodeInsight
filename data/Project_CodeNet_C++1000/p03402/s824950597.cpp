#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.14159265358979;
static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

char m[100][100] = {};
int s = 100;
int main() {
	ll a, b; cin >> a >> b;
	rep(i, 0, s) {
		rep(j, 0, s) {
			m[i][j] = ((i < s / 2) ? '#' : '.');
		}
	}

	a--; b--;
	int i = 0, j = 0;

	rep(i, 0, s) {
		if (a == 0)break;
		rep(j, 0, s) {
			if (a == 0)break;
			if (i % 2 == 0 && j % 2 == 0) {
				m[i][j] = '.';
				a--;
			}
		}
	}

	rep(i, s / 2 + 1, s) {
		if (b == 0)break;
		rep(j, 0, s) {
			if (b == 0)break;
			if (i % 2 == 0 && j % 2 == 0) {
				m[i][j] = '#';
				b--;
			}
		}
	}

	cout << 100 << " " << 100 << endl;
	rep(i, 0, s) {
		rep(j, 0, s) {
			cout << m[i][j];
		}
		cout << endl;
	}
	return 0;
}