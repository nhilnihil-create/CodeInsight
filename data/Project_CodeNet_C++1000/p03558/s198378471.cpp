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
# include <array>
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
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define RALL(qpqpq)           (qpqpq).rbegin(),(qpqpq).rend()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define RFOR(i,tptpt,ypypy)  for(LL i=(tptpt);i>=(ypypy);i--)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)

const int MAX_V = 101010;
struct edge { LL to, cost; };
vector<edge> G[MAX_V];
int d[MAX_V];

LL n;

void bfs01(int s) {
	deque<pair<LL, LL>> que;
	fill(d, d + n, INF);
	d[s] = 0;
	que.push_back(make_pair(0, s));
	while (!que.empty()) {
		pair<int, int> p = que.front(); que.pop_front();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				if (e.cost == 0)que.push_front(make_pair(d[e.to], e.to));
				else que.push_back(make_pair(d[e.to], e.to));
			}
		}
	}
}

int main() {
	cin >> n;
	REP(i, n) {
		G[i].emplace_back(edge{ (i * 10) % n ,0 });
		G[i].emplace_back(edge{ (i + 1) % n,1 });
	}
	bfs01(1);
	cout << d[0]+1 << endl;
}