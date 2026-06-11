/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 998244353;
const int maxn = 3e5 + 5;

ll fac[maxn], ifac[maxn];

ll C(ll n, ll m){return fac[n] * ifac[n - m] % INF * ifac[m] % INF;}
ll qpow(ll x, ll y){
	ll ret = 1;
	for(; y; y >>= 1){
		if(y & 1)
			(ret *= x) %= INF;
		(x *= x) %= INF;
	}
	return ret;
}

ll n, a, b, k, ans;

int main(){
	scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
	fac[0] = 1;
	REP(i, 1, n)
		fac[i] = fac[i - 1] * i % INF;
	ifac[0] = 1;
	REP(i, 1, n)
		ifac[i] = qpow(fac[i], INF - 2);
	for(ll i = 0; i <= n; ++i){
		ll j = (k - i * a) / b;
		if(i * a + j * b != k || j > n || j < 0)
			continue;
		(ans += C(n, i) * C(n, j) % INF) %= INF;
	}
	printf("%lld\n", ans);
	return 0;
}

