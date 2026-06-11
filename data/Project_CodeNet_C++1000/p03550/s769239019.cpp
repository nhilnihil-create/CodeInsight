
#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };



int main() {
	ll inf = 1e18;
	ll N;
	cin >> N;
	vector<ll> A(N + 2);
	vector<vector<ll>> dp(N + 2);
	REP(i, 0, N + 2)dp[i].resize(N + 2, 0);
	REP(i, 0, N + 2) cin >> A[i];
	reverse(A.begin(), A.end());
	REP(i, 1, N + 2) {
		dp[i][0] = abs(A[i] - A[0]);
		dp[0][i] = abs(A[i] - A[0]);
	}
	REP(i, 1, N + 2) {
		ll mx = -inf, mn = inf;
		REP(x, 0, i) maxs(mx, dp[x][i]);
		REP(y, 0, i) mins(mn, dp[i][y]);
		REP(x, i + 1, N + 2)dp[x][i] = mx;
		REP(y, i + 1, N + 2)dp[i][y] = mn;
	}
	PRI(dp[N + 1][N]);
	return 0;
}