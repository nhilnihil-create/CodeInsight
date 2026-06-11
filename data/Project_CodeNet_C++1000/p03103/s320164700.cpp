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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<pair<long long int, long long int>>v(N);
	for (auto &i : v)cin >> i.first >> i.second;
	sort(v.begin(), v.end());
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		while (M&&v[i].second) {
			M--;
			v[i].second--;
			ans += v[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}
