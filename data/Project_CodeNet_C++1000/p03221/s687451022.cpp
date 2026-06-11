#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<P> rec(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		g[a].push_back(b);
		rec[i] = P(a, b);
	}
	map<P, string> mp;
	auto make_number = [&](int a, int b) {
		string ret;
		a++;
		while (b) ret += to_string(b % 10), b /= 10;
		while (ret.size() < 6) ret += '0';
		while (a) ret += to_string(a % 10), a /= 10;
		while (ret.size() < 12) ret += '0';
		reverse(ret.begin(), ret.end());
		return ret;
	};
	rep(i, n) {
		if (g[i].size() == 0) continue;
		sort(g[i].begin(), g[i].end());
		int num = 1;
		for (int c : g[i]) {
			mp[P(i, c)] = make_number(i, num);
			num++;
		}
	}
	rep(i, m) {
		cout << mp[rec[i]] << endl;
	}
	return 0;
}