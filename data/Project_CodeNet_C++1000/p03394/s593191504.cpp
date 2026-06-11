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

int main() {
	int n;
	cin >> n;
	if (n == 3) {
		printf("2 3 25\n");
		return 0;
	}
	if (n == 4) {
		printf("2 3 4 9\n");
		return 0;
	}
	if (n== 5) {
		printf("2 3 4 6 9\n");
		return 0;
	}
	VI ans;
	int sum = 0;
	n++;
	VI d = { 0,2,3,4 };
	REP(i, n) {
		int k = 6 * (i / 4) + d[i % 4];
		sum += k;
		ans.PB(k);
	}
	if (sum % 6 == 2) {
		ans[5] = 0;
		ans.PB((n / 4 + 1) * 6);
	}
	if (sum % 6 == 3) {
		ans[6] = 0;
		ans.PB((n / 4 + 1) * 6);
	}
	if (sum % 6 == 5) {
		ans[6] = 0;
		ans.PB((n/4)*6+4);
	}
	for (auto v : ans) {
		if(v != 0)printf("%d ", v);
	}
	printf("\n");
		return 0;
}