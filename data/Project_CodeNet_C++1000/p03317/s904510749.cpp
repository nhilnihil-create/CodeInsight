#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	int N;
	int K;

	cin >> N >> K;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int ans = (N - 1) / (K - 1);
	if ((N - 1) % (K - 1) != 0) {
		ans += 1;
	}

	cout << ans << endl;

	return 0;
}

