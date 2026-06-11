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
const int maxn = 1e5 + 5;
const ll INF = 1e12 + 7;

int n;
int par[maxn], sz[maxn];
bool used[maxn];
ll mn = INF, sum = 0;
ll d[maxn], sub[maxn], dis[maxn];
vector<pair<ll, int> > vec;

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%lld", d + i);
		vec.PB(MP(d[i], i));
		mn = min(d[i], mn);
	}
	sort(vec.begin(), vec.end());
	FOR(i, 0, n) sz[i] = 1;
	FOR(i, 0, n) sub[i] = -INF;
	memset(par, -1, sizeof(par));
	for(int i = vec.size() - 1; i >= 0; --i){
		int id = vec[i].snd;
		//printf("i = %d id = %d (%d, %d)\n", i, id, vec[i].fst, vec[i].snd);
		if(d[id] == mn){
			FOR(i, 1, vec.size()){
				int u = vec[i].snd;
				dis[u] = dis[par[u]] + 1;
				sum += dis[u];
			}
			if(sum != d[id]){
				puts("-1");
				return 0;
			}
			break;
		}
		if(sub[id] == -INF) sub[id] = n - 2;
		int pos = lower_bound(vec.begin(), vec.end(), MP(d[id] - sub[id], -1)) - vec.begin();
		//printf("id = %d %d %d\n", id, d[id] - sub[id], pos);
		if(pos >= i || vec[pos].fst != d[id] - sub[id]){
			puts("-1");
			return 0;
		}
		par[id] = vec[pos].snd;
		sz[par[id]] += sz[id];
		sub[par[id]] = (n - sz[par[id]] - sz[par[id]]);
	}
	FOR(i, 0, n) if(d[i] != mn) printf("%d %d\n", i + 1, par[i] + 1);
	return 0;
}

