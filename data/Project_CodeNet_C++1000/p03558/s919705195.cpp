#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
using namespace std;
 
#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>
 
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back
 
#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
 
#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
 
#define Pi1(x) printf("%d",  (x));
#define PiL(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");
 
#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)
#define REP(L,R,k) for (int i = (L); (R) >= i; i+= (k) )
 
int myRnd(int L,int R) {
    return abs(( (rand()<<15)|rand() ) ) % (R-L+1) + L;
}
 
const int N = 1e5 + 6;
int dp[N];
 
int main () {
    srand(time(NULL));
    int k;
    Si(k);
    MEM1(dp);

    priority_queue<pii,vector<pii>,greater<pii> > pq;

    int ans=-1;
    for (int i=9;i>=1;i--) {
        dp[i%k] = i;
        pq.push({i,i%k});
    }
    while (!pq.empty()) {
        pii p=pq.top();
        pq.pop();

        if (dp[p.S] != p.F) continue;
        REP0(i,10) {
            int nxt=p.S*10+i;
            nxt %= k;

            if (nxt == 0) {
                if (ans == -1) ans = p.F + i;
                else ans = min(ans,p.F+i);
            }
            else {
                if (dp[nxt] == -1) {
                    dp[nxt] = p.F + i;
                    pq.push({dp[nxt],nxt});
                }
                else if (p.F + i < dp[nxt]) {
                    dp[nxt] = p.F + i;
                    pq.push({dp[nxt],nxt});
                }
            }
        }
    }
    Pi(ans);
}