#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 100100100;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<tuple<string, int, int> > v;
	rep (i, n) {
	  string s;
	  int p;
	  cin >> s >> p;
	  v.emplace_back(s, -p, i + 1);
	}
	sort(v.begin(), v.end());
	rep (i, n) cout << get<2>(v[i]) << endl;
	
    return 0;
}
