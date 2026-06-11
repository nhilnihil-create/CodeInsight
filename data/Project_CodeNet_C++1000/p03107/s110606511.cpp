#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s; cin >> s;
	int a = 0, b = 0;
	rep(i, 0, (int)s.size()) {
		(s[i] == '0' ? a : b) += 1;
	}
	cout << min(a, b) * 2 << endl;
	return 0;
}