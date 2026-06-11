#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rep3(i, m, n) for(ll i=m;i<=(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1000000000000000000

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

void solve_abc_d() {
	ll n, m;
	ll l_ans = 0;

	cin >> n >> m;

	V mv[8];
	ll x, y, z;
	rep(i, n) {
		cin >> x >> y >> z;

		mv[0].push_back(x + y + z);
		mv[1].push_back(-x + y + z);
		mv[2].push_back(x - y + z);
		mv[3].push_back(x + y - z);
		mv[4].push_back(-x - y + z);
		mv[5].push_back(-x + y - z);
		mv[6].push_back(x - y - z);
		mv[7].push_back(-x - y - z);
	}

	rep(i, 8) sort(RALL(mv[i]));
	
	V sum(8, 0);
	rep(i, 8) {
		rep(j, m) {
			sum[i] += mv[i][j];
		}
	}

	rep(i, 8) {
		chmax(l_ans, sum[i]);
	}


	cout << l_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
