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
	int a, b, c, x;
	int cnt = 0;
	cin >> a >> b >> c >> x;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (500 * i + 100 * j + 50 * k == x)cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}