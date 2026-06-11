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

/*-----------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(x)					(x).begin(),(x).end()
#define REP(i, n)				for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF						(int)2e9
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
int main()
{
	int A, B;
	cin >> A >> B;
	static char masu[100][100];
	REP(i, 100) {
		REP(j, 100){
			masu[i][j] = (i < 50) ? '#' : '.';
		}
	}

	A--;
	B--;
	REP(i, 50) {
		REP(j, 100){
			if (0 < A) {
				bool isMuru = false;
				if (IsOdd(i)) {
					if (IsOdd(j)) {
						isMuru = true;
					}
				}
				if (isMuru) {
					A--;
					masu[i][j] = '.';
				}
			}
		}
	}
	
	REPN(i, 51, 100) {
		REP(j, 100){
			if (0 < B) {
				bool isMuru = false;
				if (IsOdd(i)) {
					if (IsOdd(j)) {
						isMuru = true;
					}
				}
				if (isMuru) {
					B--;
					masu[i][j] = '#';
				}
			}
		}
	}

 	cout << "100 100" << endl;
	REP(i, 100) {
		REP(j, 100){
			cout << masu[i][j];
		}
	 	cout << endl;
	}

	return 0;
}

