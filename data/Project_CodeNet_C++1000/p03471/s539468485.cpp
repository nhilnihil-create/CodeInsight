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

int main() {
    ios::sync_with_stdio(false);
    int n, y;
    cin >> n >> y;
    int a, b, c;
    a = y / 10000;
    b = y / 5000;
    c = y / 1000;
    for (int i = 0 ; i <= n ; i++) for (int j = 0 ; j <= n - i ; j++) {
		if (i + j + (n - i - j) == n && i * 10000 + j * 5000 + (n - i - j) * 1000 == y) {
			cout << i << ' ' << j << ' ' << (n - i - j); 
			return 0;
		}
	}
	cout << "-1 -1 -1";
}