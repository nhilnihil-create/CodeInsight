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
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
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
	int n, h;
	cin >> n >> h;
	priority_queue<pair<int, bool>> p;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		p.push(MP(a, 1));
		p.push(MP(b, 0));
	}
	int cnt = 0;
	ll sum = 0;
	while (1) {
		if (p.top().second) {
			cnt += (h - sum + p.top().first - 1) / p.top().first;
			pv(cnt);
			return 0;
		}
		else {
			cnt++;
			sum += p.top().first;
			if (h <= sum) {
				pv(cnt);
				return 0;
			}
			p.pop();
		}
	}
	return 0;
}