
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


int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> V(N);
	REP(i, 0, N)cin >> V[i];
	ll ans = 0;
	REP(a, 0, 1+N) {
		REP(b, 0, 1+N) {
			if (a + b > K || a + b > N)continue;
			vector<ll> vec;
			ll sum = 0;
			REP(i, 0, a) {
				vec.push_back(V[i]);
				 sum+= V[i];
			}
			REP(i, 0, b) {
				vec.push_back(V[V.size() - 1 - i]);
				sum += V[V.size() - 1 - i];
			}
			sort(vec.begin(), vec.end());
			REP(i, 0, min(K - (a + b), a + b)) {
				if (vec[i] >= 0)break;
				sum -= vec[i];
			}
			maxs(ans, sum);
		}
	}
	PRI(ans);
	return 0;
}