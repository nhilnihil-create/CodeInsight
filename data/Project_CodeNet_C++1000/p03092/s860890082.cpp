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
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF=1e18+7;
const int maxn=5e3+5;

int n;
int a[maxn],pos[maxn];
ll f[maxn][maxn],g[maxn][maxn];
ll A,B;

int main(){
	scanf("%d%lld%lld",&n,&A,&B);
	REP(i,1,n) scanf("%d",a+i),pos[a[i]]=i;
	REP(i,1,n) REP(j,0,n) g[i][j]=INF;
	REP(i,1,n) REP(j,1,n){
		f[i][j]=g[i-1][j];
		if(j>pos[i]) f[i][j]+=A;
		else if(j<pos[i]) f[i][j]+=B;
		g[i][j]=min(g[i][j-1],f[i][j]);
	}
	//REP(i,1,n){
		//REP(j,1,n) printf("%lld ",f[i][j]);
		//puts("");
	//}
	printf("%lld\n",g[n][n]);
	return 0;
}

