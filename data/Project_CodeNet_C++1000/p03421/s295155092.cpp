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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<LL, LL> P;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(int i=(a);i<(b);i++)
# define RFOR(i,a,b) for(int i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

LL n, a, b;

int main() {
	cin >> n >> a >> b;
	if (a + b > n + 1) {
		cout << -1 << endl;
		return 0;
	}
	if (a*b < n) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = a - 1; i >= 0; i--) {
		cout << n - i << " ";
	}

	n -= a;
	LL num = b;
	--b;
	for (int i = 1; i < num; i++) {
		LL cur = n - b + 1;
		cur = min(cur, a);

		for (int j = cur - 1; j >= 0; j--) {
			cout << n - j << " ";
		}

		n -= cur;
		--b;
	}
	cout << endl;
}