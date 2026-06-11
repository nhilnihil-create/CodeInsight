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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)    (x).begin(),(x).end()
#define UNIQ(c)   (c).erase(unique(ALL((c))), end((c)))
#define mp        make_pair
#define eb        emplace_back
#define REP(i, a) for (int i = 0; i < (a); i++)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);

int dp[1 << 26];

int main() {
	string s;
	cin >> s;
	LL bit = 0;
	cin >> s;
	for (int i = 0; i < (1 << 26); i++)dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i < s.size(); i++) {
		bit ^= 1 << (s[i] - 'a');
		for (int j = 0; j < 26; j++) {
			dp[bit] = min(dp[bit], dp[bit ^ (1 << j)] + 1);
		}
	}
	cout << max(1, dp[bit]) << endl;
}