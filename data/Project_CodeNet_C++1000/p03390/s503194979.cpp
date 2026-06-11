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

using namespace std;

const long long int MOD = 1000000007;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N >> M;
		long long int ans = 0;
		if (N > M) {
			swap(N, M);
		}
		ans = (N - 1) * 2;
		if (M - 1 > N) {
			ans++;
		}
		long long int m = M - 1;
		for (long long int j = sqrt(N*M - 1); j >= N + 1; j--) {
			if ((N*M - 1) / j > N&&j == (N*M - 1) / j) {
				ans++;
			}
			else if ((N*M - 1) / j > N&&j < (N*M - 1) / j) {
				ans += (j - N) * 2;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}