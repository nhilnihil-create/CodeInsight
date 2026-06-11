#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MINF = 0x3f3f3f3f;
const int MAXN = 200007;
const int BASE = 26;
const int MAXS = ( 1 << BASE ) + 7;

int n;
char s[MAXN];
int sta[MAXN];
int pre[MAXS];
int dp[MAXN];

void init ();
void input ();
void work ();



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%s", s+1 );
}

void work ()
{
	// main work

	n = strlen ( s+1 );
	lpi ( i, 1, n ) sta[i] = sta[i-1] ^ ( 1 << ( s[i] - 'a' ) );

	INIT ( pre, MINF );

	INIT ( dp, MINF );
	dp[0] = 0;
	pre[0] = 0;
	lpi ( i, 1, n ) {
		lp ( j, 0, BASE ) {
			dp[i] = qmin ( dp[i], pre[sta[i]^( 1<<j )] + 1 );
		}
		dp[i] = qmin ( dp[i], pre[sta[i]] + 1 );
		pre[sta[i]] = qmin ( pre[sta[i]], dp[i] );
	}

	cout << dp[n] << endl;
}