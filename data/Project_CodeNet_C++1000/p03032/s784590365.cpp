#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int ans = 0;
	for (int a = 0; a <= min(K, N); a++) {
		for (int b = 0; a + b <= min(N, K); b++) {
			vector<int> vec;
			int sum = 0;
			for (int i = 0; i < a; i++) {
				vec.push_back(v[i]);
				sum += v[i];
			}
			for (int i = 0; i < b; i++) {
				vec.push_back(v[N - 1 - i]);
				sum += v[N - 1 - i];
			}
			sort(vec.begin(), vec.end());
			int len = vec.size();
			for (int i = 0; i < min(K - a - b, len); i++) {
				if (vec[i] < 0) sum += abs(vec[i]);
			}
			ans = max(ans, sum);
		}
	}

	cout << ans << endl;
}