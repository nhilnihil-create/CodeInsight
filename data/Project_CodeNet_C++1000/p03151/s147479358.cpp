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
#define INF                 (ll)1e9
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
struct MyCin {
	void operator()(ll &a) {
		cin >> a;	
	}
};

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N), B(N);
	for_each(ALL(A), MyCin());
	for_each(ALL(B), [](ll &a){ cin >> a; });

	ll fusoku = 0;
	vector<ll> yoyuu(N);
	REP(i, N) {
		yoyuu[i] = A[i] - B[i];
		if (yoyuu[i] < 0) fusoku -= yoyuu[i];
	}

	ll ans = 0;
	sort(ALL(yoyuu), [](ll a, ll b){return a > b; });
	REP(i, N) {
		if (fusoku <= 0) break;
		if (yoyuu[i] <= 0) break;
		fusoku -= yoyuu[i];
		ans++;
	
	}

	REP(i, N) {
		if (yoyuu[i] < 0) {
			ans++;
		}
	}

	if (fusoku > 0) ans = -1;
	cout << ans << endl;
	return 0;
}
