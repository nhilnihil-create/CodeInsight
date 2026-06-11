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

using namespace std;

const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	if (M*K < N || M + K - 1>N) {
		cout << -1 << endl;
		return 0;
	}
	int cnt = 1;
	vector<int>ans;
	for (int i = M; i >= 1; i--)ans.push_back(i);
	cnt = M + 1;
	for (int i = 1; i < K; i++) {
		int box = N - cnt + 1;
		box -= K - i - 1;
		box = min(box, (int)M);
		for (int j = box - 1; j >= 0; j--)ans.push_back(cnt + j);
		cnt += box;
	}
	for (auto i : ans)cout << N - i + 1 << " ";
	cout << endl;
}