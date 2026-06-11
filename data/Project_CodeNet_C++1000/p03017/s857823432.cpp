#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	// debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, left, right)  (a).begin()+(left),(a).begin()+(right)	// left to (right-1)

bool isok(string s) {
	int len = s.size();
	bool flag = true;
	FOR(i, 0, len - 2) {
		if (s[i] == '#'&&s[i + 1] == '#') {
			flag = false;
		}
	}
	return flag;
}

int main() {
	int a, b, c, d,n;
	string s;
	cin >>n>> a >> b >> c >> d >>s;
	if ((a < b&&c < d) || (a > b&&c > d)) {
		string tmp = s.substr(a - 1, d - a + 1);
		if (isok(tmp)) {
			ps(Yes)
		}
		else {
			ps(No);
		}
	}
	else {
		string tmp = s.substr(a - 1, d - a + 1);
		if (!isok(tmp)) {
			ps(No);
		}
		else {
			bool flag = false;
			FOR(i, b - 2, d - 2) {
				if (s[i] == '.'&&s[i + 1] == '.'&&s[i + 2] == '.') {
					flag = true;
				}
			}
			if (flag) {
				ps(Yes);
			}
			else {
				ps(No);
			}
		}
	}
	return 0;
}