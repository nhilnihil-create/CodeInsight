#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using LL = long long;
#define MAX 1e5
int main() {
	int Q;
	cin >> Q;
	vector<bool> is_prime(MAX, true), like_number(MAX, true);
	is_prime[1] = false;
	for (int i = 2; i * i<= MAX; i++) {
		for (int j = 2; i * j <= MAX; j++) {
			is_prime[i * j] = false;
		}
	}
	vector<int> sum(MAX, 0);
	for (int i = 3; i <= MAX; i++) {
		if (is_prime[i] && is_prime[(i + 1) / 2] && i % 2 == 1) {
			sum[i] = sum[i - 1] + 1;
		}
		else {
			sum[i] = sum[i - 1];
		}
	}
	for (int q = 0; q < Q; q++) {
		int li, ri;
		cin >> li >> ri;
		cout << sum[ri] - sum[li - 1] << endl;
	}


	return 0;


}