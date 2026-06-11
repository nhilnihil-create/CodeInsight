#include <iostream>
#include <string>
using namespace std;

int main() {
	int v[4] = {0, 3, 5, 7};
	string s;
	cin >> s;
	int len = s.size();
	int dp[len+1][2][2][2][2][2];
	fill((int *)dp, (int *)dp + sizeof(dp)/sizeof(int), 0);
	dp[0][0][0][0][0][0] = 1;
	for (int i = 0; i < len; i++) {
		const int D = s[i] - '0';
		for (int smaller = 0; smaller <= 1; ++smaller) {
			for (int nonzero = 0; nonzero <= 1; nonzero++) {
				for (int f3 = 0; f3 <= 1; f3++) {
					for (int f5 = 0; f5 <= 1; f5++) {
						for (int f7 = 0; f7 <= 1; f7++) {
							int x_max = smaller ? 9 : D;
							for (int x : v) {
								if (nonzero && x == 0) continue; 
								if (x > x_max) continue;
								dp[i+1][smaller || x<D][nonzero || x != 0][f3||x==3][f5||x==5][f7||x==7] += dp[i][smaller][nonzero][f3][f5][f7];
							}
						}
					}
				}
			}
		}
	}
	int ans = dp[len][0][1][1][1][1] + dp[len][1][1][1][1][1];
	cout << ans << endl;
	return 0;
}