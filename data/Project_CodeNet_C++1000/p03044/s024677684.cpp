
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

ll N;
struct node {
	bool state;
	vector<ll> link;
	vector<ll> dist;
};
vector<node> nod;

void f(ll ind, ll par) {
	REP(i, 0, nod[ind].link.size()) {
		if (nod[ind].link[i] == par) {
			if (nod[ind].dist[i] % 2 == 0) nod[ind].state = nod[par].state;
			else nod[ind].state = !nod[par].state;
			break;
		}
	}
	for (ll c : nod[ind].link) {
		if (c != par)f(c, ind);
	}
}

int main() {
	cin >> N;
	nod.resize(N);
	REP(i, 0, N-1) {
		ll u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		nod[u].link.push_back(v);
		nod[v].link.push_back(u);
		nod[u].dist.push_back(w);
		nod[v].dist.push_back(w);
	}
	nod[0].state = true;
	f(0, -1);
	REP(i, 0, N) PRI((nod[i].state ? 1 : 0));
	return 0;
}