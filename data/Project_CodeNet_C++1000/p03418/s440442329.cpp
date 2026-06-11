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
#define ALL(a)			a.begin(), a.end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF				2e9
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)	((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define	MAX_QWORD		((QWORD)0xFFFFFFFFFFFFFFFF)
#define M_PI			3.14159265358979323846
typedef long long		ll;
typedef pair<ll, ll>	P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
int main()
{
	int N, K;
	cin >> N >> K;

	ll ans = 0;
	for (int div = K + 1; div <= N; div++) {
		int floorVal = FloorN(N, div);
		int num = ((floorVal / div) * (div - K));
		if (floorVal < N) {
			int startVal = max(floorVal + 1, floorVal + K);
			num += max(0, (N - startVal + 1));
		}
		ans += num;
	}

	cout << ans << endl;
	return 0;
}

