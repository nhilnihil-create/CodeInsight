#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cassert>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define nl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << max(a + b, max(2 * a - 1, 2 * b - 1));
}
