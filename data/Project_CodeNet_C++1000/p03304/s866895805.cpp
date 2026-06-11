#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

double solve(double x, int y) {
	if (y == 1) return x;
	else {
		if (y % 2 == 0) return solve(x * 2, y / 2);
		else return solve(x * 2, y / 2) + x;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	 int n, m, d; cin >> n >> m >> d;
	 double num = double(n - d);
	 if (d != 0) num *= 2;
	 num /= double(n);
	 num /= double(n);
	 cout << setprecision(15) << num * double(m - 1) << endl;

	return 0;
}