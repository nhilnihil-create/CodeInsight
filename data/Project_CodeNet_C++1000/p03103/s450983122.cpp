#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
#include "string"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<P> data(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		data[i] = make_pair(a, b);
	}
	sort(data.begin(), data.end());
	int sum = 0;
	int p = 0;
	rep(i, n) {
		p = i;
		sum += data[i].second;
		if (sum >= m) break;
	}
	ll ans = 0;
	rep(i, p) {
		m -= data[i].second;
		ans += (ll)data[i].first * data[i].second;
	}
	ans += (ll)m * data[p].first;
	cout << ans << endl;
	return 0;
}