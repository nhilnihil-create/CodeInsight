#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
int test[213456][2], maryoku[213456];
signed main() {
	int n, w, d, a, q, l, r; cin >> n >> w >> d;
	for (int h = 0; h < n; h++) {
		for (int i = 0; i < w; i++) {
			cin >> a;
			test[a][0] = h; test[a][1] = i;
		}
	}
	for (int h = 1; h <= n * w - d; h++) {
		int sx = 0, sy = 0, gx = 0, gy = 0;
		sx = test[h][0]; sy = test[h][1];
		gx = test[h + d][0]; gy = test[h + d][1];
		if (h <= d) {
			maryoku[h] = abs(gx - sx) + abs(gy - sy);
		}
		else {
			maryoku[h] = maryoku[h - d] + abs(gx - sx) + abs(gy - sy);
		}
	}
	cin >> q; 
	for (int h = 0; h < q; h++) {
		cin >> l >> r;
		if (l <= d) { l = d; }
		if (r <= d) { r = d; }
		cout << maryoku[r - d] - maryoku[l - d] << endl;
	}
}