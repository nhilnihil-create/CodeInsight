#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	int n;
	cin >> n;
	map<int, int> d;
	rep(i, n) {
		int D;
		cin >> D;
		d[D]++;
	}
	int m;
	cin >> m;
	map<int, int> t;
	rep(i, m) {
		int T;
		cin >> T;
		t[T]++;
	}
	bool ok = true;
	for (auto p: t) {
		if (p.second > d[p.first]) ok = false;
	}
	if (ok) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}