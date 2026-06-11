#include <bits/stdc++.h>
#define Pb push_back
using namespace std;
typedef long long ll;
const int MAXN = ( 1 << 18 ) + 7;
inline int R()
{
    int rt = 0; char ch = getchar(); bool isn = false;
    for ( ; ch < '0' || ch > '9'; ch = getchar() ) isn = ch == '-' ? true : isn;
    for ( ; ch >= '0' && ch <= '9'; ch = getchar() ) rt = rt * 10 + ch - '0';
    return isn ? -rt : rt;
}

int n;
int a[MAXN];
int dp[MAXN][2];
int tp[7];
bool Cmp ( int t1, int t2 ) { return t1 > t2; }

int main()
{
	n = R();
	int lm = ( 1 << n );
	for ( int i = 0; i < lm; ++i )
		a[i] = R();
	int ans = 0;
	for ( int i = 1; i < lm; ++i )
	{
		for ( int j = i; j; j = ( j - 1 ) & i )
		{
			if ( a[j] >= dp[i][0] )
				dp[i][1] = dp[i][0], dp[i][0] = a[j];
			else
				dp[i][1] = max ( dp[i][1], a[j] );
		}
		if ( a[0] >= dp[i][0] )
			dp[i][1] = dp[i][0], dp[i][0] = a[0];
		else
			dp[i][1] = max ( dp[i][1], a[0] );
		ans = max ( ans, dp[i][0] + dp[i][1] );
		printf ( "%d\n", ans );
	}
	return 0;
}