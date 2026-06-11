#include <bits/stdc++.h>

using namespace std;

const int maxn = (1<<18) + 5;
int n;
int a[maxn];
int x[maxn][2];
int num[maxn][2];

int main() {
	cin >> n;
	for (int i = 0; i < (1<<n); ++i)
		cin >> a[i];
	memset(x, 0, sizeof(x));
	memset(num, 0, sizeof(num));
	for (int i = 1; i < (1<<n); i <<= 1)
		if (x[i][0] < a[0]) {
			x[i][0] = a[0];
			num[i][0] = 0;
		}
		else if (x[i][1] < a[0]){
			x[i][1] = a[0];
			num[i][1] = 0;
		}
	int last = 0;
	for (int i = 1; i < (1<<n); ++i) {
		if (a[i] > x[i][0]) {
			swap(x[i][0], x[i][1]);
			swap(num[i][0], num[i][1]);
			x[i][0] = a[i];
			num[i][0] = i;
		}
		else if (a[i] > x[i][1]) {
			x[i][1] = a[i];
			num[i][1] = i;
		}
		last = max(last, x[i][0]+x[i][1]);
		printf("%d\n", last);
		for (int j = 1; j < (1<<n); j <<= 1) {
			if (x[i|j][0] < x[i][0]) {
				swap(x[i|j][0], x[i|j][1]);
				swap(num[i|j][0], num[i|j][1]);
				x[i|j][0] = x[i][0];
				num[i|j][0] = num[i][0];
				if (x[i|j][1] < x[i][1] && num[i|j][1] != num[i][1]) {
					x[i|j][1] = x[i][1];
					num[i|j][1] = num[i][1];
				}
			}
			else if (x[i|j][1] < x[i][0] && num[i|j][0] != num[i][0]) {
				x[i|j][1] = x[i][0];
				num[i|j][1] = num[i][0];
			}
			else if (x[i|j][1] < x[i][1]) {
				x[i|j][1] = x[i][1];
				num[i|j][1] = num[i][1];
			}
		}
	}
	return 0;
}