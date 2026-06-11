
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

ll modpow(ll r, ll n, ll mod) {
	ll ans = 1;
	ll tmp = r;
	while (n > 0) {
		if ((n & 1) > 0) ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		n >>= 1;
	}
	return ans;
}

int main() {
	ll mod = 1e9 + 7;
	string s;
	cin >> s;
	ll N = s.size();
	vector<ll> NA(N), NC(N), QL(N), QR(N), NL(N), NR(N);
	QL[0] = 0; QR[N - 1] = 0;
	for (int i = 1; i < N; ++i) QL[i] = QL[i - 1] + (s[i - 1] == '?' ? 1 : 0);
	for (int i = N - 2; i >= 0; --i) QR[i] = QR[i + 1] + (s[i + 1] == '?' ? 1 : 0);
	REP(i, 0, N) {
		NL[i] = modpow(3, QL[i], mod);
		NR[i] = modpow(3, QR[i], mod);
	}
	NA[0] = 0; NC[N - 1] = 0;
	for (int i = 1; i < N; ++i) {
		if (s[i - 1] == '?') NA[i] = (3 * NA[i - 1] + NL[i-1]) % mod;
		else if (s[i - 1] == 'A') NA[i] = (NA[i - 1] + NL[i-1]) % mod;
		else NA[i] = NA[i - 1];
	}
	for (int i = N - 2; i >= 0; --i) {
		if (s[i + 1] == '?') NC[i] = (3 * NC[i + 1] + NR[i+1]) % mod;
		else if (s[i + 1] == 'C') NC[i] = (NC[i + 1] + NR[i+1]) % mod;
		else NC[i] = NC[i + 1];
	}
	ll ans = 0;
	REP(i, 0, N) {
		if (s[i] != 'B' && s[i] != '?')continue;
		ans += NA[i] * NC[i];
		ans %= mod;
	}
	PRI(ans);
	return 0;
}