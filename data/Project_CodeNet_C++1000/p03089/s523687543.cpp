#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
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
	int n;
	cin >> n;
	list<int> b;
	FOR(i, 1, n) {
		int B;
		cin >> B;
		b.PB(B);
	}
	vector<int> res(n + 1);
	int cnt2 = n;
	while (1) {
		int cnt = 1;
		bool isfind = false;
		auto itr2 = b.begin();
		for (auto itr = b.begin(); itr != b.end(); itr++) {
			if (*itr == cnt) {
				itr2 = itr;
				isfind = true;
			}
			cnt++;
		}
		if (!isfind) {
			ps(-1);
			return 0;
		}
		res[cnt2] = *itr2;
		b.erase(itr2);
		cnt2--;
		if (cnt2 == 0)break;
	}
	FOR(i, 1, n) {
		pv(res[i]);
	}
	return 0;
}