# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1e17 - 10;
const double PI = acos(-1);
typedef pair<LL, LL> Pll;
LL h = 0, w, n = 0, m, s, ans = 0, a[1000000] = {}, sum = 0, pos[2][2] = {}, dp[1000][1000] = {};
int flag = 0;
string str;
vector<LL>num[10000];
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a')a[0]++;
		else if (str[i] == 'b')a[1]++;
		else a[2]++;
	}
	if (abs(a[0] - a[1]) < 2 && abs(a[1] - a[2]) < 2 && abs(a[0] - a[2]) < 2)
		cout << "YES"<<endl;
	else cout << "NO" << endl;
	return 0;
}
