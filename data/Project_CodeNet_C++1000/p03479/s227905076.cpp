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
    ll x, y;
    cin >> x >> y;
    ll ans = 0, i = 1;
    while (x <= y) {
    	ans++;
    	x *= 2;
	}
	cout << ans;
}