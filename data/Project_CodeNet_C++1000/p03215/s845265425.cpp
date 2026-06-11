#include <iostream>
#include <vector>
#include <map>
using namespace std;
//see answer
int main() {
	int N, K;
	cin >> N >> K;
	vector<long long>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	map<long long, int> Nums;
	for (int i = 0; i < N; i++) {
		long long now = 0;
		for (int j = i; j < N; j++) {
			now += A[j];
			Nums[now]++;
		}
	}
	long long ans = 0;
	int num = 0;
	for (int k = 40; k >= 0; k--) {
		ans += (1ll << k);
		num = 0;
		for (auto p : Nums) {
			if ((p.first & ans) == ans) num += p.second;
		}
		if (num < K) ans -= (1ll << k);
	}
	cout << ans << endl;
}