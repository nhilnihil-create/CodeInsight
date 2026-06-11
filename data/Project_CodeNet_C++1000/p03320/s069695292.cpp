#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#define  pi acos(-1.0)
#define  eps 1e-6
#define  fi first
#define  se second
#define  rtl   rt<<1
#define  rtr   rt<<1|1
#define  bug         printf("******\n")
#define  mem(a,b)    memset(a,b,sizeof(a))
#define  name2str(x) #x
#define  fuck(x)     cout<<#x" = "<<x<<endl
#define  f(a)        a*a
#define  sf(n)       scanf("%d", &n)
#define  sff(a,b)    scanf("%d %d", &a, &b)
#define  sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define  sffff(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define  pf          printf
#define  FRE(i,a,b)  for(i = a; i <= b; i++)
#define  FREE(i,a,b) for(i = a; i >= b; i--)
#define  FRL(i,a,b)  for(i = a; i < b; i++)+
#define  FRLL(i,a,b) for(i = a; i > b; i--)
#define  FIN         freopen("data.txt","r",stdin)
#define  gcd(a,b)    __gcd(a,b)
#define  lowbit(x)   x&-x
using namespace std;
typedef long long  LL;
typedef unsigned long long ULL;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
int k;
LL sum ( LL x ) {
    int ret = 0;
    while ( x ) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int main()  {
    sf ( k );
    LL ans = 1, p = 1;
    while ( k-- ) {
        printf ( "%lld\n", ans );
        LL ans1 = ans + p, ans2 = ans + p * 10;
        if ( ans1 * sum ( ans2 ) <= ans2 * sum ( ans1 ) ) ans = ans1;
        else ans = ans2,p*=10;
    }
    return 0;
}
