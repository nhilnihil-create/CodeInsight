#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	double a, b; cin >> a >> b;
	decltype(a) c = (a + b) / 2.0;
	cout << (int)ceil(c) << endl;

	return 0;
}
