#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	
	int n, a; cin >> n;

	map<int, int> cnt;
	rep(i, 0, n) {
		cin >> a;
		cnt[a]++;
	}

	int ans = 0;
	for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
		int k = itr->first;
		int v = itr->second;
		if (k > v) ans += v;
		else if (k < v) ans += v - k;
	}
	cout << ans << endl;

	return 0;

}
