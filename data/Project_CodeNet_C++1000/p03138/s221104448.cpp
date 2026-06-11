#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <map>
#include <set>
 
#define ll long long
#define inf 0x3f3f3f3f
#define il inline
 
namespace io {
 
    #define in(a) a=read()
    #define out(a) write(a)
    #define outn(a) out(a),putchar('\n')
 
    #define I_int ll
    inline I_int read() {
        I_int x = 0 , f = 1 ; char c = getchar() ;
        while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; }
        while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; }
        return x * f ;
    }
    char F[ 200 ] ;
    inline void write( I_int x ) {
        if( x == 0 ) { putchar( '0' ) ; return ; }
        I_int tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar( '-' ) ;
        int cnt = 0 ;
        while( tmp > 0 ) {
            F[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar( F[ -- cnt ] ) ;
    }
    #undef I_int
 
}
using namespace io ;
 
using namespace std ;
 
#define N 100010
 
ll n = read(), K = read();
ll a[N], cnt[2];
 
bool cmp(int a, int b) {
    return a > b;
}
 
int main() {
    for(int i = 1; i <= n; ++i) a[i] = read();
    ll ans = 0;
    for(ll k = 42; k >= 0; --k) {
        cnt[0] = cnt[1] = 0; 
        for(int i = 1; i <= n; ++i) {
            cnt[(a[i]>>k)&1ll]++;
        }
        if(cnt[0] > cnt[1] && ans + (1ll << k) <= K) ans += (1ll << k);
    }
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += ans ^ a[i];
    }
    printf("%lld\n", sum);
    return 0;
}