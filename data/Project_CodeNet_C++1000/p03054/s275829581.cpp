#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

#define ndl cout << '\n'
#define sz(v) int(v.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define present(a, x) (a.find(x) != a.end())
#define db(x) cout << "> " << #x << " = " \
	<< (x) << '\n'
#define db2(x, y) cout << "> " << #x << " = " \
	<< (x) << ", " << #y << " = " << (y) << '\n'
#define db3(x, y, z) cout << "> " << #x << \
	" = " << (x) << ", " << #y << " = " << \
	(y) << ", " << #z << " = " << (z) << '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef map<int, int> mii;
typedef set<int> si;

int h, w, n, r, c, posU, posD, posL, posR;
string s, t;

int main() {
	ios::sync_with_stdio(false);
	cout.precision(10);
	cin >> h >> w >> n >> r >> c >> s >> t;
	posU = posD = r;
	posL = posR = c;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') {
			--posU;
		} else if (s[i] == 'D') {
			++posD;
		} else if (s[i] == 'L') {
			--posL;
		} else if (s[i] == 'R') {
			++posR;
		}
		if (posU < 1 || posD > h || posL < 1 || posR > w) {
			cout << "NO\n";
			return 0;
		}
		if (t[i] == 'U') {
			--posD;
			posD = max(posD, 1);
		} else if (t[i] == 'D') {
			++posU;
			posU = min(posU, h);
		} else if (t[i] == 'L') {
			--posR;
			posR = max(posR, 1);
		} else if (t[i] == 'R') {
			++posL;
			posL = min(posL, w);
		}
	}
	cout << "YES\n";
	return 0;
}
