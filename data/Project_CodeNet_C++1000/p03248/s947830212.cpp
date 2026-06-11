
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

int err() {
	printf("-1\n");
	return 0;
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	if (s[n - 1] == '1')return err();
	if (s[0] == '0')return err();
	REP(i, n-1) if (s[i] != s[n - i - 2])return err();
	VI comp;
	comp.PB(0);
	for (int i = 0; i <= n - i - 2; i++)if(s[i] == '1')comp.PB(i + 1);
	int k = comp.size();
	vector<PII> ans;
	REP(i, k)ans.PB(MP(i, i + 1));
	int sz = 0;
	REP(i, comp.size()) {
		while (sz < comp[i]) {
			ans.PB(MP(i - 1, ++k));
			sz++;
		}
		sz++;
	}
	while (sz < n-1) {
		ans.PB(MP(comp.size() - 1, ++k));
		sz++;
	}
	for (auto e : ans)printf("%d %d\n", e.first + 1, e.second + 1);
	return 0;
}
