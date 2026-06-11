
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

int main() {

	LL n, c; cin >> n >> c;

	vector<LL> x(n+2);
	vector<LL> v(n+2);

	for (int i = 1; i < n+1; i++) {
		cin >> x[i] >> v[i];
	}

	x[0] = 0;v[0] = 0;
	x[n + 1] = c; v[n + 1] = 0;

	//前計算
	//0-iまで0から時計まわり行ったあと0まで反時計回りで戻ったときの
	//幸福度の最大値をiで検索できるようにしたい
	
	vector<LL> tbl(n+2);

	LL sumbuf = 0;
	LL h = 0;
	for (int i = 0; i < n+2; i++) {
		LL l = x[i];
		sumbuf += v[i];

		h = max(h, sumbuf - l*2);
		tbl[i] = h;
	}

	//前計算
	//n+i-i+1まで0から反時計回りで行った時の
	//幸福度の最大値をi+1で検索できるようにしたい

	vector<LL> tbr(n + 2);

	sumbuf = 0;
	h = 0;
	for (int i = n + 1; i>=0; i--) {
		LL l = c-x[i];
		sumbuf += v[i];

		h = max(h, sumbuf - l*2);
		tbr[i] = h;
	}

	LL ans = 0;

	//左まわりで食べていく
	LL sum = 0;
	for (int i = 0; i < n+1; i++) {
		sum += v[i];
		ans = max(ans, sum - x[i] + tbr[i + 1]);
	}

	//右まわりで食べていく
	sum = 0;
	for (int i = n+1; i>=1; i--) {
		sum += v[i];
		ans = max(ans, sum - (c-x[i]) + tbl[i-1]);
	}

	cout << ans << endl;


	return 0;
}