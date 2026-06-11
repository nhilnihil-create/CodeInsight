
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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N);
	REP(i, 0, N)cin >> A[i];
	vector<ll> L(N + 1), R(N + 1);
	L[0] = 0;
	R[N] = 0;
	REP(i, 1, N + 1) {
		L[i] = gcd(A[i - 1], L[i - 1]);
		R[N - i] = gcd(A[N - i], R[N - i + 1]);
	}
	ll ans = 1;
	REP(i, 1, N + 1) {
		ll tmp = gcd(L[i - 1], R[i]);
		maxs(ans, tmp);
	}
	PRI(ans);
	return 0;
}