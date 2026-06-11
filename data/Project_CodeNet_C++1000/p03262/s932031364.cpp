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
	int n,a,r=1e9,ans=0;
	int x;
	cin >> n >> x;
	vector<int>city(n);
	if (n == 1) {
		cin >> a;
		cout << abs(x - a) << endl;
		return 0;
	}
	rep(i, n) {
		cin >> city[i];
	}
	rep(i, n - 1) {
		r = min(r, gcd(abs(city[i] - x), abs(city[i + 1] - x)));
	}
	cout << r << endl;

	return 0;
}

