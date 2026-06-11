#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <unordered_set>

using namespace std;

int main(int argc, char** argv) {
	static const int COST[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	int N, M;

	cin >> N >> M;

	vector<int> A(M);
	

	for (int i = 0; i < M; i++)
		cin >> A[i];

	sort(A.begin(), A.end(), std::greater<int>());


	// i本で作れる桁数の最大
	vector<int> dp(N+1, -1);

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < A.size(); k++) {
			int prev = i - COST[A[k]];
			if (prev >= 0 && dp[prev] != -1) {
				dp[i] = max(dp[i], dp[prev] + 1);
			}
		}
	}

	// dp[N]
	int k = dp[N]; // 桁数
	int n = N; // 残り本数
	vector<int> ans;
	
	while (k) {
		for (int i = 0; i < A.size(); i++) {
			int prev = n - COST[A[i]];

			if (prev >= 0 && dp[prev] == k - 1) {
				ans.push_back(A[i]);
				n -= COST[A[i]];
				k--;
				break;
			}
		}
	}

	for (auto a : ans)
		cout << a;
	cout << endl;

}
