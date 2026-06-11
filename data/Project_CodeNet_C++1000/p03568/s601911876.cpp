#include <iostream>
#include <vector>

using namespace std;

int solve(int N, const vector<int>& A, int i, bool even)
{
	if (i == N) {
		return even ? 1 : 0;
	}

	int ans = 0;
	for (int x = A[i] - 1; x <= A[i] + 1; ++x) {
		ans += solve(N, A, i + 1, even || x % 2 == 0);
	}
	return ans;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) {
		cin >> x;
	}
	cout << solve(N, A, 0, false) << endl;
}

