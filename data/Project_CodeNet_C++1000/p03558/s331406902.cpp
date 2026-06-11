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
constexpr int INF = 2147483647;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr double HDINF = 50000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQ(c)     (c).erase(unique(ALL((c))),(c).end())
# define LOWER(s)    transform(ALL((s)),(s).begin(),TL<char>)
# define UPPER(s)    transform(ALL((s)),(s).begin(),TU<char>)
# define mp          make_pair
# define eb          emplace_back
# define FOR(i,a,b)  for(LL i=(a);i<(b);i++)
# define RFOR(i,a,b) for(LL i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

const int MAX_V = 100000;
struct edge { int to, cost; };
int k;
vector<edge> G[MAX_V];
int d[MAX_V];
void bfs01(int s) {
	deque<pair<int, int>> que;
	fill(d, d + k, INF);
	d[s] = 0;
	que.push_back(mp(0, s));
	while (!que.empty()) {
		pair<int, int> p = que.front(); que.pop_front();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				if (e.cost == 0)que.push_front(mp(d[e.to], e.to));
				else que.push_back(mp(d[e.to], e.to));
			}
		}
	}
}
int main() {
	cin >> k;
	REP(i, k) {
		edge t;
		t.to = (i + 1) % k;
		t.cost = 1;
		G[i].emplace_back(t);
	}
	REP(i, k) {
		edge t;
		t.to = (i * 10) % k;
		t.cost = 0;
		G[i].emplace_back(t);
	}
	bfs01(1);
	cout << d[0] + 1 << endl;
}