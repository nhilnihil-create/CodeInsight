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
	double n,ave,tmp=1000;
	int ans = 0;
	cin >> n;
	vector<int>thumb(n);
	rep(i, n)cin >> thumb[i];
	ave = accumulate(all(thumb),0) / n;
	for (int i = n - 1; i >= 0; i--) {
		if (abs(thumb[i] - ave) <= tmp) {
			ans = i;
			tmp = abs(thumb[i] - ave);
		}
	}
	cout << ans << endl;
	return 0;
}

