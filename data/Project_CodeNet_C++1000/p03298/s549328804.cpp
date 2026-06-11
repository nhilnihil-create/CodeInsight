//#include "stdafx.h"
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <unordered_map>
#include <cstdint>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						2e9
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define ArrayLength(x)			(sizeof( x ) / sizeof( x[ 0 ]))
#define	MAX_QWORD				((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef unsigned long long int	QWORD;
typedef unsigned long long		SQWORD;

/*-----------------------------------------------------------------------------
　メイン
 -------------------------------------------------------------------------------*/
int N;
string S;
void getMapList(map<pair<string, string>, ll> &list, int ofs)
{
	for (int i = 0; i < (1 << N); i++) {
		string red;
		string blue;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				red += S[j + ofs];
			}
		}
		for (int j = N - 1; j >= 0; j--) {
			if (!(i & (1 << j))) {
				blue += S[j + ofs];
			}
		}
		if (ofs == 0) {
			list[pair<string, string>(red, blue)]++;
		} else {
			list[pair<string, string>(blue, red)]++;
		}
	}
}


int main()
{
	cin >> N >> S;
	map<pair<string, string>, ll> list1;
	map<pair<string, string>, ll> list2;
	getMapList(list1, 0);
	getMapList(list2, N);
	ll ans = 0;
	for (auto rp1 = list1.begin(); rp1 != list1.end(); rp1++) {
		ans += (list2[rp1->first] * rp1->second);
	}
	cout << ans << endl;
	return 0;
}

