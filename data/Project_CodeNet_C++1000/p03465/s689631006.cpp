#include<bits/stdc++.h>
#include<tr1/unordered_map>
//#include"Bignum/bignum.h"
//#define lll bignum
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 )
//#define mid ( ( l + r ) >> 1 )
#define lowbit(x) ( x & -x )
#define debug(x) cout << "#x = " << x << endl
#define re register
#define For(i, j, k) for(re int i = (j); i <= (k); i++)
#define foR(i, j, k) for(re int i = (j); i >= (k); i--)
#define cross(i, k) for(re int i = head[k]; i; i = e[i].next)
using namespace std;
typedef long long ll;
const ll N = 4000011;
const ll inf = 0x3f3f3f3f3f3f;

/*
	f[i] 表示 f[i] 是否能被表示出来。
	显然，想要找到非空子集和的中位数，就是找到小于等于 sum / 2 的最小值。
	由于如果 f[i] 能被表示出来， f[i - s] 必然能被表示出来，即子集具有对称性。
	所以直接枚举 sum + 1 >> 1 - sum 那一段是否有能被表示出来的即可。 
*/

bitset < N > f;

ll n, v, sum = 0;

namespace IO {

	inline ll read() {
		ll x = 0; bool f = 0; char ch = getchar();
		for(; !isdigit( ch ); ch = getchar()) f^=( ch == '-' );
		for(; isdigit( ch ); ch = getchar()) x = ( x << 3 ) + ( x << 1 ) + ( ch ^ 48 );
		return f? -x: x;
	}

	inline void write( ll x ) {
		if( x < 0 ) putchar( '-' ), x = -x;
		if( x > 9 ) write( x / 10 );
		putchar( x % 10 | 48 );
	}

	inline void wln( ll x ) { write( x ); putchar( '\n' ); }

}

using namespace IO;

int main() { 
	f[0] = 1; 
	n = read(); For ( i, 1, n ) v = read(), f |= f << v, sum += v; 
	For ( i, ( sum + 1 ) >> 1, sum ) if ( f[i] ) return wln (i), 0;
}

/*
3
1 2 1

2
*/

