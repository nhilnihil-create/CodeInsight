#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 29;
using ll = long long int;
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; ++i)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)


int main() {
	string s;
	cin >> s;

	int res = 0;
	int t = 0;
	rep(i, s.size()) {
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			++t;
		}
		else {
			res = max(res, t);
			t = 0;
		}
	}
	res = max(res, t);

	cout << res << endl;
}