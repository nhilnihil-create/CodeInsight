#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> A;
	A.resize(N);
	vector<int> counter(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		counter[A[i]]++;
	}

	int kind = 0;
	for (int i = 1; i <= N; i++) {
		if (counter[i] > 0)
			kind++;
	}

	sort(counter.begin(), counter.end());

	int ans = 0;

	if (kind > K) {
		for (int i = N - K; i >= 1; i--) {
			if (counter[i] == 0)
				break;
			else
				ans += counter[i];
		}
	}

	cout << ans << endl;

	return 0;
}