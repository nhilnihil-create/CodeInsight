#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)
#define rep_r(i,s,n)for(ll i=n-1;i>=s;i--)

#define repe_r(i,s,n)for(ll i=s;i<=n;i++)
static const ll MOD = 1e9 + 7;
static const ll MAX_L = 1e9 + 7;

int main() {
	ll a, b; cin >> a >> b;
	cout << 100 << " " << 100 << endl;

	a--; b--;
	rep(i, 0, 100) {
		if (i < 50) {
			rep(j, 0, 100) {
				if (i & 1 && j & 1) {
					if (b-- > 0)cout << '#';
					else cout << '.';
				}
				else cout << '.';
			}
		}
		else {
			rep(j, 0, 100) {
				if (i & 1 && j & 1) {
					if (a-- > 0)cout << '.';
					else cout << '#';
				}
				else cout << '#';
			}
		}
		cout << endl;
	}

	return 0;
}