#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int n;
	int cnt = 0;
	int ans = 0;
	cin >> n;
	int a[2][100];
	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[1][i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= i)cnt += a[1][j];
			else { cnt += a[0][j]; }
		}
		cnt += a[0][i];
		if (cnt > ans)ans = cnt;
		cnt = 0;
	}
	cout << ans << endl;

}