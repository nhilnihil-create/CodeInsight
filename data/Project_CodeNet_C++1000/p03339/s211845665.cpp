#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	vector<int> accE(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		accE[i + 1] = accE[i] + (S[i] == 'E');
	}

	int ans = N;
	for (int i = 0; i < N; ++i) {
		int nWtoE = i - accE[i];
		int nEtoW = accE[N] - accE[i + 1];
		ans = min(ans, nWtoE + nEtoW);
	}
	cout << ans << endl;
}
