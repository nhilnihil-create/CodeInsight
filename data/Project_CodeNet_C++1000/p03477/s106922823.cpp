#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	if (a + b > c + d) {
		cout << "Left" << endl;
	}
	else if (a + b == c + d) {
		cout << "Balanced" << endl;
	}
	else if (a + b < c + d) {
		cout << "Right" << endl;
	}
}