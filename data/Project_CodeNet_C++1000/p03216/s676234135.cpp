
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

//typedef
//------------------------------------------
template<class T> using v=vector<T>;
using VI = v<int>;
using VVI = v<v<int>>;
using VS = v<string>;
using PII = pair<int, int>;
using LL = long long;
using ULL = unsigned long long;
using VLL = v<LL>;
using VVLL = v<VLL>;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

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

//update
//------------------------------------------
template<class T>inline T updmax(T& target, T val) { return target = max(target, val); }
template<class T>inline T updmin(T& target, T val) { return target = min(target, val); }

char s[1000005];

int main() {
	int n,  qq;
	scanf("%d%s%d", &n, s, &qq);
	REP(q, qq) {
		int k;
		scanf("%d", &k);
		LL d = 0, m = 0, c = 0, dm = 0, ans = 0;
		REP(i, n) {
			if (i >= k) {
				if (s[i - k] == 'D') {
					dm -= m;
					d--;
				}
				else if (s[i - k] == 'M') m--;
			}
			if (s[i] == 'D') d++;
			else if (s[i] == 'M') {
				dm += d;
				m++;
			}
			else if (s[i] == 'C') {
				ans += dm;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}