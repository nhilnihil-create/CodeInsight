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
#define rep(i,n) for(int i = 0; i <= n; i++)

int main() {
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	int ans = 0;
	rep(i, a) {
		rep(j, b) {
			rep(k, c) {
				int sum = 500 * i + 100 * j + 50 * k;
				if (sum == x) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}