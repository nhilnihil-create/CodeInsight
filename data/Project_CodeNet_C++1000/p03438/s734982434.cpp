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
int main()
{
	auto myCin = [](ll &a){cin >> a;};
	ll N;
	cin >> N;
	vector<ll> a(N), b(N);
	for_each(ALL(a), myCin);
	for_each(ALL(b), myCin);

	string ans = "No";

	ll amari = 0;
	ll fusoku = 0;
	REP(i, N) {
		ll diff = abs(a[i] - b[i]);
		if (a[i] < b[i]) {
			amari += diff / 2;
		} else {
			fusoku += diff;	
		}
	}

	if (fusoku <= amari) {
		ans = "Yes";
	}
	
	cout << ans << endl;
	return 0;
}
