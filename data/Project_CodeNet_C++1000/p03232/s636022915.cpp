
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

const int MAX = 100005;
const int N = 100005;
LL fact[MAX], invfact[MAX], inv[MAX];
LL cumsum[N];

// テーブルを作る前処理
void init() {
	fact[0] = fact[1] = 1;
	invfact[0] = invfact[1] = 1;
	inv[0] = inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		invfact[i] = invfact[i - 1] * inv[i] % MOD;
	}
	for (int i = 0; i < MAX - 1; i++) {
		cumsum[i + 1] = (cumsum[i] + inv[i + 1]) % MOD;
	}
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	LL ret = 0;
	REP(i, n) {
		LL a;
		scanf("%lld", &a);
		ret =  (ret + (a * ((cumsum[i + 1] + cumsum[n - i] - 1 + MOD) % MOD))%MOD)%MOD;
	}
	cout << (fact[n] * ret) % MOD << endl;
	return 0;
}