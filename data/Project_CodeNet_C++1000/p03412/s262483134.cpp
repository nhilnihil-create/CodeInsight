
#define _CRT_SECURE_NO_WARNINGS

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


int a[200005], b[200005];
int n, ans;

int main()
{
	//入力
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);

	//上位bitから走査
	for (int v = (1 << 28); v; v >>= 1)
	{
		//vまで全部1がたったbitをつくり,各a,bとアンドを取ることで
		//a,bのvより上位のビットだけを消す

		//vを上位から走査しているので、今必要ない分に絞って消せるので
		//上書きしてもかまわない
		for (int i = 0; i < n; i++) a[i] &= (v * 2 - 1);
		for (int i = 0; i < n; i++) b[i] &= (v * 2 - 1);

		//二部探索するためのソート
		sort(a, a + n); sort(b, b + n);

		int t = 0;

		for (int i = n - 1, j = 0, k = 0, l = 0; i >= 0; i--)
		{
			//vを超える最小の添字がj
			//v以上で2*vを超える最小の添字がk
			while (j < n && a[i] + b[j] < v) j++;
			while (k < n && a[i] + b[k] < 2 * v) k++;

			//3*vを超える最小の添字がl
			while (l < n && a[i] + b[l] < 3 * v) l++;

			//vビット目に立ってるビットが偶数か奇数か計算する
			t += k - j + n - l;
			t &= 1;
		}
		if (t) ans |= v;
	}
	printf("%d\n", ans);
	return 0;
}