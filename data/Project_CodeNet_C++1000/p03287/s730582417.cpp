#include <iostream>
#include <map>
using namespace std;
//see answer
int main() {
	int N, M;
	cin >> N >> M;
	map<int, long long> Nums;
	int now = 0;
	Nums[0]++;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		now = (now + A % M) % M;
		Nums[now]++;
	}
	long long ans = 0;
	for (auto p : Nums) ans += p.second * (p.second - 1) / 2;
	cout << ans << endl;
}
