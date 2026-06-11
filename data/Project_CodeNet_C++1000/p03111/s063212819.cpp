#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;
	vector<int> L(N);
	for (int i = 0; i < N; i++) cin >> L[i];
	int ans = 3000;
	for (int bit = 0; bit < pow(4, N); bit++) {
		int cost = 0;
		int a[3] = { 0,0,0 };
		int num[3] = { 0,0,0 };
		for (int i = 0; i < N; i++) {
			int n = bit % (int)pow(4, i + 1) / (int)pow(4, i);
			if (n < 3) {
				a[n] += L[i];
				num[n]++;
			}
		}
		if (num[0] == 0 || num[1] == 0 || num[2] == 0) continue;
		for (int i = 0; i < 3; i++) cost += 10 * (num[i] - 1);
		cost += abs(A - a[0]) + abs(B - a[1]) + abs(C - a[2]);
		ans = min(cost, ans);
	}
	cout << ans << endl;
}