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
	ll x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x);
	vector<ll> b(y);
	vector<ll> c(z);
	FOR(i, 0, x-1) {
		cin >> a[i];
	}
	FOR(i, 0, y - 1) {
		cin >> b[i];
	}
	FOR(i, 0, z - 1) {
		cin >> c[i];
	}
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	int pa = SZ(a) - 1;
	int pb = SZ(b) - 1;
	int pc = SZ(c) - 1;
	priority_queue<pair<ll, tuple<int, int, int>>> que;
	set<tuple<int, int, int>> used;
	ll ten = a[pa] + b[pb] + c[pc];
	que.push(MP(ten, MT(pa, pb, pc)));
	used.insert(MT(pa, pb, pc));

	int dx[3] = { 1,0,0 };
	int dy[3] = { 0,1,0 };
	int dz[3] = { 0,0,1 };

	FOR(i, 1, k) {
		pair<ll, tuple<int, int, int>> res = que.top();
		pv(res.first);
		que.pop();
		FOR(j,0,2){
			pa = get<0>(res.S) - dx[j];
			pb = get<1>(res.S) - dy[j];
			pc = get<2>(res.S) - dz[j];
			if (pa >= 0 && pb >= 0 && pc >= 0 && used.find(MT(pa, pb, pc)) == used.end()) {
				ll ten = a[pa] + b[pb] + c[pc];
				/*dump(ten);
				dump(pa);
				dump(pb);
				dump(pc);
				cout << endl;*/
				que.push(MP(ten, MT(pa, pb, pc)));
				used.insert(MT(pa, pb, pc));
			}
		}
	}
	return 0;
}