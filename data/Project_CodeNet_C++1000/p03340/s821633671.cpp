#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int right = 0;
	int sum = 0;
	long long ans = 0;
	for (int left = 0; left < N; ++left) {
		while (right < N && (sum^A[right]) == (sum + A[right])) {
			sum += A[right]; 
			right++;
		}
		ans += right - left; 
		sum -= A[left];
	}
	cout << ans << endl;
	return 0;
}
