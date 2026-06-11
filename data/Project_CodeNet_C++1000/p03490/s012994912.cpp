#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) (a*a)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

const int N = 8001;
int x[N], y[N];
int _dpx[2][2*N], _dpy[2][2*N];

int main() {
	int *dpx[2] = { &_dpx[0][N], &_dpx[1][N] };
	int *dpy[2] = { &_dpy[0][N], &_dpy[1][N] };
	string str;
	int gx, gy;
	cin >> str >> gx>>gy;
	str += "T";
	int n = str.length();
	
	int t = 0, cnt = 0, xidx = 0, yidx = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'F')cnt++;
		else {
			if (t == 0)gx -= cnt;
			else if (cnt != 0) {
				if (t % 2)y[yidx++] = cnt;
				else x[xidx++] = cnt;
			}
			cnt = 0;
			t++;
		}
	}
	dpx[0][0] = 1;
	dpy[0][0] = 1;
	REP(i, xidx) {
		memset(_dpx[(i + 1) % 2], 0, sizeof(_dpx[(i + 1) % 2]));
		FOR(j, -N, N + 1) if (dpx[i % 2][j])dpx[(i + 1) % 2][j - x[i]] = dpx[(i + 1) % 2][j + x[i]] = 1;
	}
	REP(i, yidx) {
		memset(_dpy[(i + 1) % 2], 0, sizeof(_dpy[(i + 1) % 2]));
		FOR(j, -N, N + 1) if (dpy[i % 2][j])dpy[(i + 1) % 2][j - y[i]] = dpy[(i + 1) % 2][j + y[i]] = 1;
	}
	if (dpx[xidx % 2][gx] == 1 && dpy[yidx % 2][gy] == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}