//#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 100000000
using namespace std;
using ll = long long;


int main() {
	int d, g;
	cin >> d >> g;
	vector<int> p(d), c(d);
	int ans = INF;
	rep(i, d) {
		cin >> p[i] >> c[i];
	}
	//問題のセットをすべて解くか解かないかでbit全探索
	rep(i, 1 << d) {
		bitset<10> bit(i);
		int scr = 0, tmp = 0;
		rep(j, d) {
			if (bit[j]) {
				scr += 100 * p[j] * (j + 1) + c[j];
				tmp += p[j];
			}

		}
		if (i != (1 << d) - 1) {
			int j = d - 1;
			while (bit[j] && j > 0)j--;
			int pj = p[j];
			while (scr < g && pj > 1) {
				scr += 100 * (j + 1);
				tmp++;
				pj--;
			}
		}
		if (scr >= g) {
			ans = min(tmp, ans);
		}
	}
	cout << ans << endl;

}