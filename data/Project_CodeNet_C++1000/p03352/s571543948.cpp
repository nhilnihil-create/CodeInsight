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

int f(int x) {
	int ret = 0;
	while ((ret + 1) * (ret + 1) <= x) ret++;
	return ret;
}

int main() {
	int x;
	cin >> x;
	if (x == 1) {
		cout << 1 << endl;
		return 0;
	}
	int ans = 0;
	while (ans == 0) {
		for (int i = 2; i <= f(x); i++) {
			int tmp = x;
			while (tmp % i == 0) tmp /= i;
			if (tmp == 1) {
				ans = x;
				break;
			}
		}
		x--;
	}
	cout << ans << endl;
	return 0;
}