#include <bits/stdc++.h>
#define Pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 7;

inline int R()
{
    int rt = 0; char ch = getchar(); bool isn = false;
    for ( ; ch < '0' || ch > '9'; ch = getchar() ) isn = ch == '-' ? true : isn;
    for ( ; ch >= '0' && ch <= '9'; ch = getchar() ) rt = rt * 10 + ch - '0';
    return isn ? -rt : rt;
}

int n, a[MAXN];
ll lm;
int s[MAXN], t[MAXN << 1];

inline int Lowbit ( int x ) { return x & -x; }

void Add ( int pos, int val )
{
	pos += n + 1;
	for ( ; pos <= n + n + 1; pos += Lowbit ( pos ) )
		t[pos] += val;
}

int Query ( int pos )
{
	pos += n + 1;
	int rt = 0;
	for ( ; pos; pos -= Lowbit ( pos ) )
		rt += t[pos];
	return rt;
}

bool Chk ( int na )
{
	memset ( t, 0, sizeof t );
	for ( int i = 1; i <= n; ++i )
		s[i] = ( a[i] < na ? -1 : 1 );
	ll rt = 0;
	Add ( 0, 1 );
	int nv = 0;
	for ( int i = 1; i <= n; ++i )
	{
		nv += s[i];
		rt += Query ( nv );
		Add ( nv, 1 );
	}
	return rt >= lm;
}

int main()
{
	n = R(), lm = 1ll * n * ( n + 1 ) / 2 / 2 + 1;
	lm = 1ll * n * ( n + 1 ) / 2 - lm + 1;
	for ( int i = 1; i <= n; ++i )
		a[i] = R();
	int nl = 1, nr = 1e9, ans;
	while ( nl <= nr )
	{
		int mid = nl + nr >> 1;
		if ( Chk ( mid ) )
			ans = mid, nl = mid + 1;
		else
			nr = mid - 1;
	}
	printf ( "%d\n", ans );
	return 0;
}