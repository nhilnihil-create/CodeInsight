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
typedef long long			ll;
typedef unsigned long long	ull;
typedef pair<ll, ll>		P;
typedef vector<ll>			VLL;
typedef vector<VLL>			VVLL;
typedef vector<VVLL>		VVVLL;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int N, K;
vector<ll> X, Y;

bool checkOne(ll x1, ll x2, ll y1, ll y2)
{
	if (x1 > x2) {
		swap(x1, x2);
	}
	if (y1 > y2) {
		swap(y1, y2);
	}

	int incCnt = 0;
	REP(i, N) {
		if ((x1 <= X[i])&&(X[i] <= x2)) {
			if ((y1 <= Y[i])&&(Y[i] <= y2)){
				incCnt++;
			}
		}
	}

	return (K <= incCnt);
}

ull compExec()
{
	ull area = (ull)1e18 * 5;

	REP(xi, N) {
		REPN(xj, xi + 1, N) {
			REP(yi, N) {
				REPN(yj, yi + 1, N) {
					ull areaOne = abs((X[xi] - X[xj]) * (Y[yi] - Y[yj]));
					if (checkOne(X[xi], X[xj], Y[yi], Y[yj])) {
						area = min(areaOne, area);
					}
				}
			}
		}
	}
	return area;
}

int main()
{
	cin  >> N >> K;
	X.resize(N);
	Y.resize(N);
	REP(i, N) cin >> X[i] >> Y[i];
	cout <<  compExec() << endl;
	return 0;
}
