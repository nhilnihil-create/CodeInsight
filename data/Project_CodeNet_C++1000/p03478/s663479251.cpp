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
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, ans = 0;
    for (int i = 1 ; i <= n ; i++) {
    	string c = to_string(i);
    	for (int j = 0 ; j < c.length() ; j++) x += c[j] - '0';
    	if (x >= a && x <= b) ans += i;
    	x = 0;
	}
	cout << ans;
}