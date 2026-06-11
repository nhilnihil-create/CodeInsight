#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100005;

int n; ll now, ans;
bool vis[MAXN];

struct Seg{
	int id, l, r;
	Seg() {}
	Seg( int id, int l, int r ) :
		id(id), l(l), r(r) {}
} lft[MAXN], rght[MAXN];

inline bool lcmp( const Seg &a, const Seg &b ){
	return a.l > b.l;
}

inline bool rcmp( const Seg &a, const Seg &b ){
	return a.r < b.r;
}

inline void solve( int init ){
	now = 0; memset( vis, 0, sizeof vis );
	int L = 1, R = 1, pos = 0;
	for( int i = 1, t = init; i <= n; ++i, t ^= 1 ){
		if( t == 0 ){
			while( vis[lft[L].id] ) ++L;
			vis[lft[L].id] = 1;
			if( pos >= lft[L].l && pos <= lft[L].r ) continue;
			now += abs( lft[L].r - pos );
			pos = lft[L].r;
		} else{
			while( vis[rght[R].id] ) ++R;
			vis[rght[R].id] = 1;
			if( pos >= rght[R].l && pos <= rght[R].r ) continue;
			now += abs( rght[R].l - pos );
			pos = rght[R].l;
		}
	}
	ans = max( ans, now + abs(pos) );
}

int main(){
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ){
		int x, y; scanf( "%d%d", &x, &y );
		lft[i] = Seg( i, x, y );
		rght[i] = Seg( i, x, y );
	}
	sort( lft+1, lft+n+1, rcmp );
	sort( rght+1, rght+n+1, lcmp );
	solve(0); solve(1);
	printf( "%lld\n", ans );
	return 0;
}