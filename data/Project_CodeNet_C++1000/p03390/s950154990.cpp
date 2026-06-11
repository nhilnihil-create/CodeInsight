# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
# include <cstdlib>
# include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2147483647;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr double HDINF = 50000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define LOWER(s)    transform(ALL((s)),(s).begin(),TL<char>)
# define UPPER(s)    transform(ALL((s)),(s).begin(),TU<char>)
# define FOR(i,a,b)  for(LL i=(a);i<(b);i++)
# define RFOR(i,a,b) for(LL i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

int q;
LL a, b;

LL check(LL a, LL x) {
	LL left = 1, right = x + 1;
	while (left + 1 < right) {
		LL mid = (left + right) / 2;
		if ((a + mid)*(x + 1 - mid) > (a + mid - 1)*(x + 1 - mid + 1)) left = mid;
		else right = mid;
	}
	return left;
}


int main() {
	cin >> q;
	REP(Q, q) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		int ans = a - 1;
		LL left = 0, right = b;
		while (left + 1 < right) {
			LL mid = (left + right) / 2;
			LL x = check(a, mid);
			if ((a + x)*(mid + 1 - x) < a*b) left = mid;
			else right = mid;
		}
		cout << ans + left << endl;
	}
}