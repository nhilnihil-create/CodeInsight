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
	string A, B; cin >> A >> B;
	vector<string> a(3), b(3);
	REP(i, 3) a[i] = A[i];
	REP(j, 3) b[j] = B[j];
	if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}