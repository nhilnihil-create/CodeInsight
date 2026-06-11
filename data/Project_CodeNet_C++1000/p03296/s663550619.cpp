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
	int n;
	cin >> n;
	int s, a, cnt = 0;
	cin >> s;
	rep(i, n - 1) {
		cin >> a;
		if (a == s) {
			s = a + 10001 + cnt;
			cnt++;
		}
		else s = a;
	}
	cout << cnt << endl;
	return 0;
}

