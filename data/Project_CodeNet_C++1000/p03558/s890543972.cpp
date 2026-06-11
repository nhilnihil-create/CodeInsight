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
typedef pair<LL, LL> Vec2;
LL h, w, n, m, s, ans = 0, num = 1, sum = 0;
bool f[1000000000];
string str;
struct Edge { int to, cost; };
vector<Edge>edge[10000];
Pll bfs(LL s) {
	f[s] = 1;
	deque<Pll> pq;
	pq.push_front(Pll(s, 1));
	while (!pq.empty()) {
		LL vv = pq.front().first, pc = pq.front().second;
		pq.pop_front();
		if (vv % n == 0)
			return Pll(vv,pc);
		f[vv] = 1;
		if (f[(vv * 10) % n] == 0) {
			pq.push_front(Pll((vv * 10)%n , pc));
		}
		if (f[(vv + 1) % n] == 0) {
			pq.push_back(Pll((vv + 1) % n, pc + 1));
		}
	}
}
int main() {
	cin >> n; 
	Pll xx = bfs(1);
	cout << xx.second << endl;
	return 0;
}
