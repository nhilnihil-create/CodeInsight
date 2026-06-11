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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (d >= abs(a - b) && d >= abs(c - b) || abs(a - c) <= d) cout << "Yes";
	else cout << "No";
}
/*
*/