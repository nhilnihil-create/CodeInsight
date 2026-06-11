#include <iostream>
using namespace std;

const int N = 305;

int a[N][N];
bool mark[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			a[i][j] = (c - 'a');
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
			//	cout << i << " " << j << " " << k << " " << (j + k) % n << " " << (i - k + n) % n << endl;
				if (a[i][j] != a[(j + k) % n][(i - k + n) % n]) {
					mark[k] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < n; k++) {
		if (!mark[k]) {
			ans += n;
		}
	}
	cout << ans << endl;
	return 0;
}
