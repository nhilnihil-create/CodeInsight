#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define double long double
#define INF LLONG_MAX/10000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int a, b;
char c[100][100];
int d[] = { -1,-1,-1,0,0,1,1,1 };
int e[] = { -1,0,1,-1,1,-1,0,1 };
signed main() {
	cout << 100 << " " << 100 << endl;
	cin >> a >> b;
	rep(i, 50) {
		rep(j, 100) {
			c[i][j] = '.';
			c[i + 50][j] = '#';
		}
	}
	int cnt = 0;
	for (int i = 51; i < 100; i++) {
		rep(j, 100) {
			if (cnt == a - 1)goto kaage;
			bool f = false;
			rep(k, 8) {
				if (0 <= i + d[k] && i + d[k] < 100 && 0 <= j + e[k] && j + e[k] < 100 && c[i + d[k]][j + e[k]] == '.')f = true;
			}
			if (f)continue;
			c[i][j] = '.';
			cnt++;
		}
	}
kaage:;
	cnt = 0;
	rep(i, 49) {
		rep(j, 100) {
			if (cnt == b - 1)goto kaage2;
			bool f = false;
			rep(k, 8) {
				if (0 <= i + d[k] && i + d[k] < 100 && 0 <= j + e[k] && j + e[k] < 100 && c[i + d[k]][j + e[k]] == '#')f = true;
			}
			if (f)continue;
			c[i][j] = '#';
			cnt++;
		}
	}
kaage2:;
	rep(i, 100) {
		rep(j, 100)cout << c[i][j];
		cout << endl;
	}
	return 0;
}