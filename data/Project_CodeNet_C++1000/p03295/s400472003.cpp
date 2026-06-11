#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;


int main() {

	int n, m;
	cin >> n >> m;
	vector<P> c(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		c[i] = make_pair(a, b);
	}

	sort(all(c));

	vi bre = {};

	rep(i, m) {
		if (bre.size() == 0)bre.push_back(c[m - 1 - i].first + 1);

		int k = bre[bre.size() - 1];
		int s, t;
		if (k <= c[m - 1 - i].first)s = bre.size();
		else s = *lower_bound(all(bre), c[m - 1 - i].first);
		if (k <= c[m - 1 - i].second)t = bre.size();
		else t = *lower_bound(all(bre), c[m - 1 - i].second);

		if (s == t)bre.push_back(c[m - 1 - i].first + 1);
	}

	cout << bre.size() << endl;

}