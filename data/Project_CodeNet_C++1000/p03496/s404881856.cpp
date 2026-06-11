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
bool check(const VLL &movList, int movMax, int stPos, int endPos)
{
	if (movMax < abs(endPos)) {
		return false;
	}

	movMax++;
	int dpSizeMax = movMax * 2;
	VVLL dp(2, VLL(dpSizeMax, INF));
	stPos += movMax;
	endPos += movMax;

	int nowIdx = 0;
	int nextIdx = 1;
	dp[nowIdx][stPos] = 0;
	for (auto movOne : movList) {
		fill(&dp[nextIdx][0], &dp[nextIdx][dpSizeMax - 1], INF);
		REP(i, dpSizeMax) {
			if (0 == dp[nowIdx][i]) {
				dp[nextIdx][i + movOne] = 0;
				dp[nextIdx][i - movOne] = 0;
			}		
		}
		swap(nowIdx, nextIdx);
	}
	
	return dp[nowIdx][endPos] != INF;
}

int main()
{
	int N;
	cin >> N;
	VLL a(N);

	int idx = 0;
	int maxAbs = 0;
	REP(i, N) {
		cin >> a[i];
		if (maxAbs <= abs(a[i])) {
			maxAbs = abs(a[i]);
			idx = i;
		}
	}

	vector<P> ans;
	REP(i, N) {
		if (idx != i) {
			a[i] += a[idx];
			ans.emplace_back(idx, i);
		}
	}

	if (0 < a[idx]) {
		REP(i, N - 1) {
			if (a[i + 1] < a[i]) {
				a[i + 1] += a[i];
				ans.emplace_back(i, i + 1);
			}
		}
	} else {
		for (int i = N - 1; i > 0; i--) {
			if (a[i - 1] > a[i]) {
				a[i - 1] += a[i];
				ans.emplace_back(i, i - 1);
			}
		}
	}
	
	cout << ans.size() << endl;
	for (auto oneAns : ans) {
		cout << oneAns.first + 1 << " " << oneAns.second + 1 << endl;
	}
	return 0;
}
