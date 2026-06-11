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


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	ll M, K, X;
	cin >> M >> K;
	X = 1LL << M;
	if (X <= K) {
		PRI(-1);
		return 0;
	}
	if (M == 0)PRI("0 0");
	else if (M == 1) {
		if (K == 0)PRI("0 0 1 1");
		else PRI(-1);
	}
	else {
		REP(i, 0, X)if (i != K)PRI(i << " ");
		PRI(K << " ");
		for (int i = X-1; i >= 0; --i) if (i != K)PRI(i << " ");
		PRI(K);
	}
	return 0;
}


