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
#define rep(i,n) for(int i = 0; i < n; i++)
const int INF = 1001001001;

//n以上の最小の10の倍数を返す
int f(int n) {
	int ret = 1;
	while (!(10 * (ret - 1) < n && n <= 10 * ret)) ret++;
	return ret * 10;
}

int main() {
	vector<int> dif(5);
	int sum = 0;
	rep(i, 5) {
		int a;
		cin >> a;
		int b = f(a);
		sum += b;
		dif[i] = b - a;
	}
	sort(dif.begin(),dif.end());
	cout << sum - dif[4] << endl;
	return 0;
}