
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>


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

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define loop(n) FOR(i,0,n)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

//台形の面積計算、速度が高さで幅は1、縦横2倍にして計算したから面積4分の1
double calcarea(int a, int b) {
	return (double)(a + b)/8.0;
}

// 山形のとんがりができると誤差がでるので、0.5秒ごとに計算すべきだが
// 途中少数を扱うのがめんどくさいので縦横2倍してあとで4分の1することにした
// 結局最後の足し上げのところで少数使っているが、これはさけられないのだろうか…

//うまい人がこぞってdp解でやってるので、チェック
//このソースは解説放送のやり方

//やるだけ感はあるが、含む含まないとかめんどくさいので図をきちんと書くの推奨
int main() {
	int n; cin >> n;

	vector<int> t(n);
	vector<int> v(n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		sum += t[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> limitspeed(sum*2+1,INF);
	
	//入力を一つの時間軸にまとめる
	int now = 0;
	for (int i = 0; i < n; i++) {
		for (int j = now; j <= t[i]*2+now; j++) {
			limitspeed[j] = min(limitspeed[j], v[i]*2);
		}

		now += t[i] * 2;
	}
	
	//始点側からの速度の更新
	limitspeed[0] = 0;
	for (int i = 0; i < sum * 2; i++) {
		limitspeed[i + 1] = min(limitspeed[i + 1], limitspeed[i] + 1);
	}

	//終点側からの速度の更新
	limitspeed[sum * 2] = 0;
	for (int i = sum * 2; i >0 ; i--) {
		limitspeed[i-1] = min(limitspeed[i-1], limitspeed[i] + 1);
	}

	//面積の足し上げ
	double ans = 0.0;

	for (int i = 0; i < sum * 2; i++) {
		ans += calcarea(limitspeed[i], limitspeed[i + 1]);
	}

	//出力
	cout << fixed << setprecision(12) << ans << endl;


	return 0;
}