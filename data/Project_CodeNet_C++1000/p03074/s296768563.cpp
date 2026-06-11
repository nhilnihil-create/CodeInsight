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
#define MT make_tuple
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> b;
	vector<int> w;
	int cnt = 0;
	int bcnt, wcnt;
	while (1) {
		bcnt = 0;
		wcnt = 0;
		while (cnt<=n-1 && s[cnt] == '1') {
			bcnt++;
			cnt++;
		}
		b.push_back(bcnt);
		if (cnt == n) {
			break;
		}
		while (cnt <= n - 1 && s[cnt] == '0') {
			wcnt++;
			cnt++;
		}
		w.push_back(wcnt);
		if (cnt == n) {
			b.push_back(0);
			break;
		}
	}

	if (SZ(w) == 0) {
		pv(bcnt);
		return 0;
	}

	k = min(ll(k), SZ(w));
	int res = 0;
	int lim = SZ(w) - k;
	FOR(i, 0, lim) {
		int tmp = 0;
		FOR(j, i, i+k-1) {
			tmp += b[j];
			tmp += w[j];
		}
		tmp += b[i + k];
		res = max(res, tmp);
	}

	pv(res)
}