#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int prime(int n) {
	for (int i = 2 ; i < n ; i++) if (n % i == 0) return 0;
	return 1;
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int t, x, y;
    int a = 0, b = 0, l = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> t >> x >> y;
		int k = abs(a - x) + abs(b - y);
		if (t - l < k || ( k - t + l ) % 2) {
			cout << "No";
			return 0;
		}
		a = x;
		b = y;
		l = t;
	}
	cout << "Yes";
}