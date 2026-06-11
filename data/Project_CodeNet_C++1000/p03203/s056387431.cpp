# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        (wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

int h, w, n;
int sa[202020];
vector<pair<int, int>>v;
int main() {
	cin >> h >> w >> n;
	int ans = h;
	REP(i, n) {
		int x, y;
		cin >> x >> y;
		v.emplace_back(make_pair(x, y));
	}
	sort(ALL(v));
	int num = 0;
	REP(i, v.size()) {
		if (v[i].first - v[i].second == num) {
			num++;
			sa[v[i].first] = num;
		}
	}
	for (int i = 1; i < 202020; i++) {
		if (sa[i] >= 1)continue;
		sa[i] = sa[i - 1];
	}
	REP(i, v.size()) {
		if (v[i].first - v[i].second >= sa[v[i].first])ans = min(ans, v[i].first - 1);
	}
	cout << ans << endl;
}