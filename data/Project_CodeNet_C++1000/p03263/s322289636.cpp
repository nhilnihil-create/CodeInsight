#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define MAX 510
int H, W;
int a[MAX][MAX] = {}, temp[MAX][MAX] = {};
int cnt;
bool flag[MAX][MAX] = {};

signed main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> a[i][j];
			temp[i][j] = a[i][j];
		}
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (a[i][j] % 2 == 1 && j != W) { 
				a[i][j + 1]++, a[i][j]--; cnt++; 
			}
		}
		if (a[i][W] % 2 == 1 && i != H) {
			a[i + 1][W]++, a[i][W]--; cnt++; 
		}
	}
	cout << cnt << endl;;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (temp[i][j] % 2 == 1 && j != W) {
				temp[i][j + 1]++, temp[i][j]--;
				cout << i << " " << j << " " << i << " " << j + 1 << endl;
			}
		}
		if (temp[i][W] % 2 == 1 && i != H) {
			temp[i + 1][W]++, temp[i][W]--;
			cout << i << " " << W << " " << i + 1 << " " << W << endl;
		}
	}
	return 0;
}
