#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N];
int n, sum[N], f[(1<<26)];
int main(){
	scanf( "%s", s + 1 );
	n = strlen( s + 1 );
	for( int i = 1; i <= n; i++ ) sum[i] = sum[i-1] ^ (1<<(s[i]-'a')); 
	memset(f,0x3f,sizeof(f)); f[0] = 0;
	for( int i = 1; i <= n; i++ )
		for( int j = 0; j < 26; j++ )
			f[sum[i]] = min( f[sum[i]], f[sum[i]^(1<<j)] + 1 );
	printf( "%d\n", max( f[sum[n]], 1 ) );
	return 0;
}