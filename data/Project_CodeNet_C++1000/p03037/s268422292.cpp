#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> L(M), R(M);
	for (int i = 0; i < M; i++) cin >> L[i] >> R[i];

	int maxL = 1;
	int minR = N;

	for (int i = 0; i < M; i++) {
		maxL = max(maxL, L[i]);
		minR = min(minR, R[i]);
	}

	int ans = minR - maxL + 1;
	ans = max(ans, 0);

	cout << ans << endl;
}