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

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N + 1);
	for (int i = 1; i <= N; i++)cin >> v[i];
	for (int i = 1; i <= N; i++)v[i] += v[i - 1];
	unsigned long long int ans = ULLONG_MAX;
	for (int i = 1; i <= N; i++) {
		unsigned long long int box = K * N;
		box += K * i;
		unsigned long long int cnt = 2;
		for (int j = N; j >= 1; j -= i) {
			if (j == N)box += (v[j] - v[max(j - i, 0)])*(cnt*cnt+1);
			else box += (v[j] - v[max(j - i, 0)])*(cnt*cnt-(cnt-1)*(cnt-1));
			cnt ++;
		}
		ans = min(ans, box);
	}
	cout << ans << endl;
	return 0;
}
