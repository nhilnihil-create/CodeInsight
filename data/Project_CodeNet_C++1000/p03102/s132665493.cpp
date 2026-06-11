#include "iostream"
#include "math.h"
#include "algorithm"
#include "string"
#include "vector"
#include "deque"
#include "cmath"
using namespace std;
typedef long long ll;

int main() {
	int a[30][30];
	int b[30];
	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = c;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt += a[i][j] * b[j];
		}
		if (cnt > 0) {
			ans++;
		}
		cnt = c;
	}
	cout << ans << endl;
}