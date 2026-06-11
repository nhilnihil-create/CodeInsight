#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>
#include <set>
#include <array>
#include <stdio.h>
#include <string.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
#define CONTAINS_VEC(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define ARY_REVERSE(v,a) (reverse((v), (v)+(a)))
#define REP(i, n) for (int (i)=0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
#define CONTAINS_SET(m, a) (m).find((a)) != m.end()
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }

set<string> se;

signed main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int vx = x2 - x1;
	int vy = y2 - y1;

	int vx3 = -vy;
	int vy3 = vx;

	int x3 = x2 + vx3;
	int y3 = y2 + vy3;

	vx = x3 - x2;
	vy = y3 - y2;

	int vx4 = -vy;
	int vy4 = vx;

	int x4 = x3 + vx4;
	int y4 = y3 + vy4;

	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}

