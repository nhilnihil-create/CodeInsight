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
	vector<int> vec(3);
	rep(i, 3) cin >> vec[i];
	sort(vec.begin(), vec.end());
	//a <= b <= c
	int a = vec[0], b = vec[1], c = vec[2];
	//a,bをcにできないか考える。
	int ans = 0;
	//c-b回だけa,bを+1する
	ans += (c - b);
	a += (c - b);
	b = c;
	while (a < c) {
		a += 2;
		ans++;
	}
	if (a > c) cout << ans + 1 << endl;
	else cout << ans << endl;
	return 0;
}