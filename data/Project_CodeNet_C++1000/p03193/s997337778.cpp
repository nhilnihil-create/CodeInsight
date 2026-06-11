#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	int n, h, w, a, b;
	int cnt = 0;
	int ac, bc;
	cin >> n >> h >> w;
	rep(i, n) {
		cin >> a >> b;
		ac = a / h;
		bc = b / w;
		cnt += min(ac, bc);
	}
	cout << cnt << endl;
	return 0;
}
