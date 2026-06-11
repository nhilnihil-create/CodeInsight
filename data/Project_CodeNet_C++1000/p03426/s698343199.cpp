#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int a[100010], b[100010];
int main() {
	int sum[100010] = { 0 };
	int h, w, d;
	cin >> h >> w >> d;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int c;
			cin >> c;
			a[c] = i;
			b[c] = j;
		}
	}
	for (int i = 0; i < d; i++) {
		for (int j = d + i + 1; j <= h * w; j += d) {
			sum[j] = abs(a[j] - a[j - d]) + abs(b[j] - b[j - d]);
			sum[j] += sum[j - d];
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum[y] - sum[x] << endl;
	}
}
