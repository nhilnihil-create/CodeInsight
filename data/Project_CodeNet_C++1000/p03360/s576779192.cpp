#include<algorithm>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<deque>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c;
	int k;
	int ans = 0;
	cin >> a >> b >> c >> k;
	int max = a;
	if (max < b)max = b;
	if (max < c)max = c;
	REP(i, k) {
		if (max == a) {
			a *= 2;
			max = a;
		}
		else if (max == b) {
			b *= 2;
			max = b;
		}
		else if (max == c) {
			c *= 2;
			max = c;
		}
	}
	cout << a + b + c << endl;
}
