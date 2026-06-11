
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


double eps = 1e-4;



double integ(double v1, double v2, double dx) {
	return (v1 + v2) * dx / 2.0;
}

int main() {
	double inf = 1e18;
	ll N; cin >> N;
	vector<double> T(N+1);
	vector<double> V(N);
	T[0] = 0;
	REP(i, 1, N+1) {
		cin >> T[i];
		T[i] += T[i - 1];
	}
	REP(i, 0, N) cin >> V[i];
	vector<double> val(2 * T.back() + 1);
	vector<double> tbl_r(N), tbl_l(N);
	tbl_l[0] = inf;
	tbl_r[N - 1] = inf;
	REP(i, 1, N)tbl_l[i] = min(tbl_l[i - 1], V[i - 1] - T[i]);
	for (int i = N - 2; i >= 0; --i) tbl_r[i] = min(tbl_r[i + 1], V[i + 1] + T[i + 1]);
	val[0] = 0;
	int area = 0;
	REP(i, 1, 2 * T.back() + 1) {
		double t = (double)i / 2.0;
		if (t > T[area+1]) ++area;
		double ceil_val = min(t, T.back() - t);
		mins(ceil_val, V[area]);
		mins(ceil_val, tbl_l[area] + t);
		mins(ceil_val, tbl_r[area] - t);
		if (val[i - 1] + 0.5 < ceil_val + eps) val[i] = val[i - 1] + 0.5;
		else if (val[i - 1] < ceil_val + eps) val[i] = val[i - 1];
		else val[i] = val[i - 1] - 0.5;
	}
	double ans = 0;
	REP(i, 1, 2 * T.back() + 1) ans += integ(val[i], val[i - 1], 0.5);
	PRIF(ans, 5);
	return 0;
}