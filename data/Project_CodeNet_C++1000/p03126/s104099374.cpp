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

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)
const int INF = 1001001001;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> foods(m);
	rep(i, n) {
		int k;
		cin >> k;
		rep(j, k) {
			int a;
			cin >> a;
			a--;
			foods[a]++;
		}
	}
	int ans = 0;
	for (int c : foods) {
		if (c == n) ans++;
	}
	cout << ans << endl;
	return 0;
}