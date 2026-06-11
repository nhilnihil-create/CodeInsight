#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll unsigned long long

const ll MOD = 1000000000000000000;

int main() {
	//入力
	vector<vector<int>> c(3, vector<int>(3));
	rep(i, 3) {
		rep(j, 3) {
			cin >> c[i][j];
		}
	}

	//処理
	string ans = "No";
	vector<int> a(3);
	vector<int> b(3);
	int a1 = min(min(c[0][0], c[0][1]),c[0][2]) + 1;
	int a2 = min(min(c[1][0], c[1][1]), c[1][2]) + 1;
	int a3 = min(min(c[2][0], c[2][1]), c[2][2]) + 1;
	rep(i, a1) {
		a[0] = i;
		int flg0 = 0;
		rep(ii, 3) {
			b[ii] = c[0][ii] - a[0];
			if (b[ii] < 0) {
				++flg0;
				break;
			}
		}
		if (flg0 == 0) {
			rep(j, a2) {
				int flg1 = 0;
				a[1] = j;
				rep(jj, 3) {
					if (b[jj] != c[1][jj] - a[1]) {
						++flg1;
						break;
					}
				}
				if (flg1 == 0) {
					rep(k, a3) {
						int flg2 = 0;
						a[2] = k;
						rep(kk, 3) {
							if (b[kk] != c[2][kk] - a[2]) {
								++flg2;
								break;
							}
						}
						if (flg2 == 0) {
							ans = "Yes";
							std::cout << ans << endl;
							return 0;
						}
					}
				}
			}
		}
	}

	//出力
	std::cout << ans << endl;

	return 0;
}
