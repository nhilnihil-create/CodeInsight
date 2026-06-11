#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>

using namespace std;
#define ALL(x)			(x).begin(),(x).end()
#define REP(i, n)		for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)	for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF				(int)2e9
#define MOD				(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)		(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)		(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)	((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)		(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)		(!IsOdd((x)))						
#define M_PI			3.14159265358979323846
typedef long long		ll;
typedef pair<ll, ll>	P;
typedef vector<ll>		VLL;
typedef vector<VLL>		VVLL;
typedef vector<VVLL>	VVVLL;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	int N, C;
	cin >> N >> C;
	VLL s(N), t(N), c(N);
	REP(i, N) {
		cin >> s[i] >> t[i] >> c[i];
		c[i]--;
	};

	VVLL cSum(C, VLL(100001, 0));
	REP(i, N) {
		ll ch = c[i];
		cSum[ch][s[i]]++;
		cSum[ch][t[i]]--;
	}

	ll ans = 0;
	ll nowNum = 0;
	VLL totalSum(100001, 0);
	REP(i, totalSum.size()) {
		REP(j, C) {
			if (1 == cSum[j][i]) {
				nowNum++;
			}
		}
		ans = max(ans, nowNum);
		REP(j, C) {
			if (-1 == cSum[j][i]) {
				nowNum--;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
