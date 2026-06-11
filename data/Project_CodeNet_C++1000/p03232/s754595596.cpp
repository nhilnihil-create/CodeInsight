#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int N;
	cin >> N;
	vector<int> inv(N + 1); inv[1] = 1;
	for (int i = 2; i <= N; ++i) inv[i] = (long long)(inv[mod % i]) * (mod - mod / i) % mod;
	int fact = 1;
	for (int i = 1; i <= N; ++i) fact = (long long)(fact)* i % mod;
	vector<int> harmony(N + 1);
	for (int i = 1; i <= N; ++i) {
		harmony[i] = (harmony[i - 1] + (long long)(fact) * inv[i]) % mod;
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		int multiplier = ((harmony[i + 1] + harmony[N - i]) % mod - fact + mod) % mod;
		ans = (ans + (long long)(a)* multiplier) % mod;
	}
	cout << ans << endl;
	return 0;
}