
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

const int MAXN = 8000;

int main() {

	string s; cin >> s;
	s.push_back('*');
	int x, y; cin >> x >> y;

	int cnt = 0;
	vector<int> d[2];
	int p = 0;

	int i = 0;
	while (i < s.size()) {
		if (s[i] == 'F') {
			cnt++;
		}
		else {

			d[p].push_back(cnt);
			p = (p + 1) % 2;
			cnt = 0;

			while (s[i] == 'T' && s[i+1]=='T') {
				i++;
				p = (p + 1) % 2;
			}
		}

		i++;
	}

	//マイナスの座標をそのまま書きたいが配列の添字はマイナスにできないので
	//プラスの方向にずらしておく

	//dp[i番目の方向転換のときに][座標j]にいることができるか?


	vector<vector<int>> dp(MAXN, vector<int>(MAXN*2+1));

	dp[0][8000] = 1;

	for (int i = 0; i < d[0].size(); i++) {

		for (int j = 0; j < MAXN*2+1; j++) {

			if (j - d[0][i] > 0)dp[i+1][j] |= dp[i][j - d[0][i]];
			if (i == 0)continue;

			if (j + d[0][i] <MAXN*2)dp[i+1][j] |= dp[i][j+d[0][i]];
		}
	}

	bool okx = dp[d[0].size()][8000 + x];

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN*2+1; j++) {
			dp[i][j] = 0;
		}
	}
	
	dp[0][8000] = 1;

	for (int i = 0; i < d[1].size(); i++) {

		for (int j = 0; j < MAXN * 2+1; j++) {

			if (j - d[1][i] > 0)dp[i + 1][j] |= dp[i][j - d[1][i]];
			if (j + d[1][i] < MAXN * 2)dp[i + 1][j] |= dp[i][j + d[1][i]];
		}
	}

	bool oky = dp[d[1].size()][8000 + y];

	if (okx && oky)cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}