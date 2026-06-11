
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

int dp[100000];
int s[100000];

int main() {
	int x;
	cin >> x;
	REP(i, 100000) {
		int k = i;
		while (k) {
			s[i] += k % 10;
			k /= 10;
		}
	}
	priority_queue<PII, vector<PII>, greater<PII>> q;
	memset(dp, 0x7f, sizeof(dp));
	int ans = 0x7f7f7f7f;
	FOR(i, 1,10) {
		int n = x * i;
		q.push(MP( n % 10, n / 10));
	}
	while (!q.empty()) {
		auto tmp = q.top();
		q.pop();
		if (dp[tmp.second] < tmp.first)continue;
		ans = min(ans, s[tmp.second] + tmp.first);
		REP(i, 10) {
			int n = x * i + tmp.second;
			int k = n % 10 + tmp.first;
			if (dp[n / 10] > k) {
				dp[n / 10] = k;
				q.push(MP(k, n / 10));
			}
		}
	}
	cout << ans << endl;
	return 0;
}