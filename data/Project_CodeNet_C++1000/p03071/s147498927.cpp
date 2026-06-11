#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define int64 long long
#define uint64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define coutfix(i) cout << fixed << setprecision(i)
using namespace std;

int main()
{
	int64 aa, bb;
	cin >> aa >> bb;
	int64 ans = max(aa, bb);
	ans += max(min(aa, bb), max(aa, bb) - 1);
	cout << ans << endl;
}
