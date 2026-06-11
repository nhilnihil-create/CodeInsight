#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int train[501][501];
int sum[501][501];

int get_sum(int y1, int x1, int y2, int x2){
	return sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1];
}


int main(){
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		train[l][r]++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			sum[i][j] = train[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	for (int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		cout << get_sum(l, l, r, r) << endl;
	}
	return 0;
}