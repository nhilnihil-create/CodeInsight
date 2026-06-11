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
#include <assert.h>
#include <functional>
#include <unordered_map>

using namespace std;

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						(1000 * 1000 * 1000 * 2)
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
// メイン
int main()
{
	int M, K;
	cin >> M >> K;
	int valMax = 1 << M;

	vector<int> a;
	if (K == 0) {
		// K 0, 0, 1, 1, … N, N
		REP(i, valMax) {
			a.emplace_back(i);
			a.emplace_back(i);
		}
	} else {
		// K 0, 1, … N K N … 1, 0
		int xorRes = 0;
		REP(i, valMax) {
			if (i != K) {
				xorRes ^= i;
			}
		}
		if (xorRes != K) {
			cout << -1 << endl;
			return 0;
		}

		// 出力作成
		a.emplace_back(K);
		REP(i, valMax) {
			if (i != K) {
				a.emplace_back(i);
			}
		}
		a.emplace_back(K);
		for (int i = valMax - 1; 0 <= i; i--) {
			if (i != K) {
				a.emplace_back(i);
			}
		}
	}

	// 出力
	REP(i, a.size()) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
