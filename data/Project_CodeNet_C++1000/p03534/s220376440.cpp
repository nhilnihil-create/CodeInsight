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


string s;
int main() {
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')a++;
		if (s[i] == 'b')b++;
		if (s[i] == 'c')c++;
	}
	cout << ((max({ a,b,c }) - min({ a,b,c }) <= 1) ? "YES" : "NO") << endl;
}