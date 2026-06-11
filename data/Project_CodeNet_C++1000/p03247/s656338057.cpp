#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
#include <cstdio>
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
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

const int N = 1005;
int x[N], y[N];
int u[N], v[N];
char* d = "RUDL";

int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)scanf("%d%d", &x[i], &y[i]);
	int parity = (x[0] ^ y[0]) & 1;
	REP(i, n) {
		if ((x[i] ^ y[i] ^ parity) & 1) {
			printf("-1\n");
			return 0;
		}
		u[i] = x[i] + y[i];
		v[i] = x[i] - y[i];
	}
	VI arms((parity) ? 1 : 2, 1);
	FOR(i, 1, 31)arms.PB(1 << i);
	int m = arms.size();
	printf("%d\n", m);
	REP(i, m)printf("%d ", arms[i]);
	printf("\n");
	REP(i, n) {
		VI dir(m, 0);
		for (int j = m - 1; j >= 0; j--) {
			//u
			if (u[i] < 0) {
				u[i] += arms[j];
				dir[j] |= 2;
			}
			else {
				u[i] -= arms[j];
			}
			//v
			if (v[i] < 0) {
				v[i] += arms[j];
				dir[j] |= 1;
			}
			else {
				v[i] -= arms[j];
			}
		}
		string ret;
		REP(j, m) {
			ret += d[dir[j]];
		}
		cout << ret << endl;
	}
	return 0;
}