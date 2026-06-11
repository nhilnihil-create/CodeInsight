#include <iostream>
using namespace std;
const int MAX = 100000;

int main() {
	int n, c;
	cin >> n >> c;
	int A[30][MAX+10] = {};
	int imos[MAX+10] = {};
	for (int i = 0; i < n; i++) {
		int s, t, ci;
		cin >> s >> t >> ci;
		ci--;
		A[ci][s]++;
		A[ci][t]--;
	}
	for (int i = 1; i <= MAX; i++) {
		for (int j = 0; j < 30; j++) {
			if (A[j][i] == 1) imos[i-1] += 1;
			else if (A[j][i] == -1) imos[i] -= 1;
		}
	}
	int ans = 0;
	for (int i = 0; i <= MAX; i++) {
		ans = max(ans, imos[i]);
		imos[i+1] += imos[i];
	}
	cout << ans << endl;
	return 0;
}