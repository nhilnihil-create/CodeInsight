
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
#include <cassert>

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

using pll = pair<long long, long long>;

int main() {

	//入力　この時点では加工していないx,yのまま
	int N; cin >> N;
	vector<pll> pos(N);

	for (int i = 0; i < N; ++i) cin >> pos[i].first >> pos[i].second;

	//u=x+yというデカルト→マンハッタンという変換をして
	//最初の点の変換後の座標のパリティ
	int par = (abs(pos[0].first) + abs(pos[0].second)) % 2;
	
	//各点に対して
	for (int i = 0; i < N; ++i) {

		//変換後のパリティを計算
		int par2 = (abs(pos[i].first) + abs(pos[i].second)) % 2;

		//u=x+y;v=x-yとしてu,vをペアにし、0～n-1の番号で管理する
		pos[i] = pll(pos[i].first + pos[i].second, pos[i].first - pos[i].second);

		//全ての点のパリティが一致していないと達成できないので
		//最初の点とパリティがことなる点が見つかった時点で
		//-1を出力し終了
		if (par2 != par) {
			cout << -1 << endl;
			return 0;
		}
	}

	//2ベキのアームを大きい順番に用意する
	vector<long long> d;
	for (int i = 30; i >= 0; --i) d.push_back(1LL << i);

	//パリティが偶数なら1のアームを追加して,奇数の場合に帰着する
	if (par % 2 == 0) d.push_back(1);

	//腕に関する情報が確定したので、出力しておく
	cout << d.size() << endl;
	for (int j = 0; j < d.size(); ++j) cout << d[j] << " ";
	cout << endl;


	//構築段階

	//u=x+y;v=x-y;という変換において
	//Lはxがマイナス　u-d,v-d
	//Rはxがプラス	  u+d,v+d
	//Dはyがマイナス  u-d,v+d
	//Uはyがプラス    u+d,v-d

	//dを足したか、引いたかでLRDUが決まる

	for (int i = 0; i < N; ++i) {

		//u,vにdを足したか引いたか管理するための変数
		int xdir, ydir;

		//今u方向,v方向のどの位置にいるか
		long long xsum = 0, ysum = 0;

		//大きい腕から順番に各腕に対して,足すか、引くかを決めていく
		for (int j = 0; j < (int)d.size(); ++j) {

			//di>di-1～d0の和となるので 
			//例えば 8>4+2+1みたいなこと

			//もし現在の位置より、目標の位置が大きければ
			//足すしかない。引いてしまうと、それ以下の腕を全部足しても
			//元の位置にも戻れない
			if (xsum <= pos[i].first) xdir = 1, xsum += d[j];
			else xdir = -1, xsum -= d[j];
			
			//yも同様
			if (ysum <= pos[i].second) ydir = 1, ysum += d[j];
			else ydir = -1, ysum -= d[j];

			//上の式どおり、u,vが決定したのでx,yでの方向が決まる
			if (xdir == 1 && ydir == 1) cout << "R";
			else if (xdir == 1 && ydir == -1) cout << "U";
			else if (xdir == -1 && ydir == -1) cout << "L";
			else cout << "D";
		}

		cout << endl;
	}
}