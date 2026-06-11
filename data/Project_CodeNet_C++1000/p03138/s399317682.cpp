#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	long long K;
	cin >> N >> K;
	vector<int> Nums(40);
	vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < 40; j++) {
			if (A[i] & (1ll << j)) Nums[j]++;
		}
	}
	long long ans = 0;
	for (int j = 39; j >= 0; j--) {
		if (Nums[j] * 2 <= N) ans += (1ll << j);
		if (ans > K) ans -= (1ll << j);
	}
	long long sum = 0;
	for (long long a : A) sum += (a ^ ans);
	cout << sum << endl;
}
