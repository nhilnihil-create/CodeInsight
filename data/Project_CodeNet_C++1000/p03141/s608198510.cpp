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
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
typedef long long           ll;
#define REP(i, n)           for (ll i = 0 ; i < (ll)n ; ++i)
#define REPN(i, m, n)       for (ll i = m ; i < (ll)n ; ++i)
#define INF                 (ll)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef pair<ll, ll>	    P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> abSum(N);
	REP(i, N) {
		cin >> A[i] >> B[i];
		abSum[i] = A[i] + B[i];
 	}
	sort(ALL(abSum));
	reverse(ALL(abSum));

	ll ans = 0;
	REP(i, N) {
		if (IsEven(i)) {
			ans += abSum[i];
		}
	}

	ans -= accumulate(B.begin(), B.end(), (ll)0);
	cout << ans << endl;
	return 0;
}
