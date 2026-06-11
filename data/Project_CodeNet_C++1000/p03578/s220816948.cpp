#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n,m,d,t;
	bool ans = true;
	cin >> n;
	map<int, int>md, mt;
	rep(i, n) {
		cin >> d;
		md[d]++;
	}
	cin >> m;
	rep(i, m) {
		cin >> t;
		mt[t]++;
	}
	for (auto q : mt) {
		if (q.second > md[q.first])ans = false;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

