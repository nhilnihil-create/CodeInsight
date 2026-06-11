
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
#include <regex>
#include <numeric>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

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
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 998244353
#define SQ(x) ((x)*(x))

const int N = 200005;

LL x[N];
LL sx[N];

int main() {
	LL n, c;
	cin >> n >> c;
	REP(i, n)scanf("%lld", &x[i + 1]);
	REP(i, n)sx[i + 1] = sx[i] + x[i + 1];
	LL ret = 0x7fffffffffffffff;
	FOR(r, 1,n+1) {
		LL e = n;
		LL m = 3;
		LL tmp = n*c+r*c;
		while (e > 0) {
			tmp += max(m,5LL)*(sx[e]- sx[max(e-r, 0LL)]);
			e -= r;
			m += 2;
			if (tmp > ret)break;
		}
		ret = min(ret, tmp);
	}
	cout << ret << endl;
	return 0;
}