#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<vector<int>> d(c, vector<int>(c));
	vector<vector<int>> C(n, vector<int>(n));
	rep(i, c) {
		rep(j, c) {
			cin >> d[i][j];
		}
	}
	rep(i, n) {
		rep(j, n) {
			cin >> C[i][j];
			C[i][j]--;
		}
	}
		int ans = 1000000000;
		vector<int> a1(c), a2(c), a0(c);
		rep(i, c) {
			rep(j, n) {
				rep(k, n) {
					if ((j + k) % 3 == 0) a0[i] += d[C[j][k]][i];
					else if ((j + k) % 3 == 1) a1[i] += d[C[j][k]][i];
					else a2[i] += d[C[j][k]][i];
				}
			}
		}
		for (int i = 0; i < c - 2; i++) {
			for (int j = i + 1; j < c - 1; j++) {
				for (int k = j + 1; k < c; k++) {
					ans = min(ans, a0[i] + a1[j] + a2[k]);
					ans = min(ans, a0[i] + a2[j] + a1[k]);
					ans = min(ans, a1[i] + a0[j] + a2[k]);
					ans = min(ans, a1[i] + a2[j] + a0[k]);
					ans = min(ans, a2[i] + a1[j] + a0[k]);
					ans = min(ans, a2[i] + a0[j] + a1[k]);
				}
			}
		}
		cout << ans << endl;
}