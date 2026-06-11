#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;

	V<V<P>> e(n);

	rep(i, m) {
		int l, r, d;
		cin >> l >> r >> d;
		l--;r--;
		e[l].push_back(P(d, r));
		e[r].push_back(P((-1) * d, l));
	}

	queue<int> que;
	vi x(n, INF);

	rep(i, n) {
		if (x[i] != INF)continue;
		x[i] = 0;
		que.push(i);

		while (!que.empty()) {
			int v = que.front();que.pop();
			for (auto p : e[v]) {
				int vv = p.second;
				int d = p.first;
				if (x[vv] == INF) {
					x[vv] = x[v] + d;
					que.push(vv);
				}
				else if (x[vv] != x[v] + d) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;

}