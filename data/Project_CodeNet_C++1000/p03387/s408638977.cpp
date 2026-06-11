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
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
	int n[3], a, b, c;
	cin >> a >> b >> c;
	n[0] = a;
	n[1] = b;
	n[2] = c;
	sort(n, n + 3);
	int x = n[2] - n[1] + (n[1] - n[0]) / 2;
    if ((n[1] - n[0]) % 2 == 0) cout << x;
    else cout << x + 2;
}
/*
*/