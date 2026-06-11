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
#define RANGE(a, l, r)  (a).begin()+(l),(a).begin()+(r)


int main() {
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<pair<ll, ll>> cb;
	FOR(i, 0, n-1) {
		cin >> a[i];
	}
	sort(ALL(a));

	FOR(i, 1, m) {
		ll b, c;
		cin >> b >> c;
		cb.push_back(MP(c, b));
	}
	sort(ALL(cb));
	
	vector<ll> change(m);
	RFOR(i,m-1,0){
		auto itr = lower_bound(ALL(a), cb[i].F);
		//change[i] = min((itr - a.begin()), int(cb[i].S));
		change[i] = itr - a.begin();
	}

	ll nowidx = 0;
	RFOR(i, m - 1, 0) {
		if (change[i] > nowidx) {
			int cnt = 0;
			FOR(j, nowidx, change[i] - 1) {
				a[j] = cb[i].F;
				cnt++;
				nowidx++;
				if (cnt == cb[i].S)break;
			}
			//nowidx = change[i];
		}
	}
	ll res = accumulate(ALL(a), 0LL);
	pv(res);
	return(0);
}