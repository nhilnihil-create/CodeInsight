#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int n, m;
	vector<int> like(30, 0);
	cin >> n >> m;
	rep(i, n) {
		int k; cin >> k;
		rep(j, k) {
			int a; cin >> a;
			a--;
			like[a]++;
		}
	}
	int cnt = 0;
	rep(i, m) {
		if (like[i] == n) cnt++;
	}
	cout << cnt << endl;
	return 0;
}