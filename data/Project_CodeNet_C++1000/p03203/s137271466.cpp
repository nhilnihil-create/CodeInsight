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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> W >> H >> N;
	vector<vector<int>>x(W + 2);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		x[a].push_back(b);
	}
	for (int i = 1; i <= H; i++)x[W + 1].push_back(i);
	bitset<200001>bs;
	bs.flip(0);
	for (int i = 1; i <= W; i++) {
		bs |= bs << 1;
		for (auto j : x[i])bs.set(j, 0);
		for (auto j : x[i + 1]) {
			if (bs.test(j)) {
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
