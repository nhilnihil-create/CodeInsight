
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
char str[N];
int cnt[N][2];
bool dead[N];

int main() {
	int n, m;
	cin >> n >> m >> str;
	VVI g(n);
	REP(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
		cnt[y][str[x] - 'A']++;
		cnt[x][str[y] - 'A']++;
	}
	queue<int> q;
	REP(i, n) if (cnt[i][0] == 0 || cnt[i][1] == 0)q.push(i);
	int live = n;
	while (!q.empty()) {
		auto tmp = q.front();
		q.pop();
		if (dead[tmp])continue;
		for (auto to : g[tmp]) {
			if (dead[to])continue;
			cnt[to][str[tmp] - 'A']--;
			if (cnt[to][0] == 0 || cnt[to][1] == 0)q.push(to);
		}
		dead[tmp] = true;
		live--;
	}
	if (live)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}