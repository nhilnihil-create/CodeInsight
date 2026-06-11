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

typedef long long           ll;
typedef pair<ll, ll>	    P;

#define ALL(x)              (x).begin(),(x).end()
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

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
template<class T>
class Ruiseki
{
private:
	int num;

public:
	vector<T> sumVal;
	Ruiseki(const vector<T> &srcVal)
	{
		num = srcVal.size();
		sumVal.resize(num + 1, 0);
		for (int i = 0; i < num; i++) {
			sumVal[i + 1] = sumVal[i] + srcVal[i];
		}
	}

	T GetSumAll()
	{
		return sumVal[num];
	}

	T GetSumRange(int startIdx, int stopIdx)
	{
		return sumVal[stopIdx] - sumVal[startIdx];
	}

	T GetSumFromTop(int stopIdx)
	{
		return sumVal[stopIdx] - sumVal[0];
	}

	T GetSumFromEnd(int startIdx)
	{
		return sumVal[num] - sumVal[startIdx];
	}
};

int main()
{
	ll N;
	cin >> N;
	vector<ll> A(N);
	for_each(ALL(A), [](ll &a){cin >> a;});

	Ruiseki<ll> ruiseki(A);
	map<ll, ll> mp;
	for_each(ruiseki.sumVal.begin() + 1, ruiseki.sumVal.end(), [&](ll val){mp[val]++;});
	ll ans = mp[0];
	for_each(mp.begin(), mp.end(), [&ans](P mpOne){ans += mpOne.second * (mpOne.second - 1) / 2; });
	cout << ans << endl;
	return 0;
}
