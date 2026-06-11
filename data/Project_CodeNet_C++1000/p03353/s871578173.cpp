#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc098() {
	string s;
	ll K;
	cin >> s >> K;

	vector<string> sum;
	std::map<string, bool> m;
	string tmp;
	rep(i, s.size()) {
		rep(j, 5) {
			tmp = s.substr(i, j + 1);
			if (m.find(tmp) == m.end()) {
				m.emplace(tmp, true);
				sum.push_back(tmp);
			}
		}
	}

	sort(ALL(sum));

	cout << sum[K - 1] << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc098();

	return 0;
}
