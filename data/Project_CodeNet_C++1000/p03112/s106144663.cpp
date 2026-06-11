#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m, q;
long long a[101000], b[101000];
long long solve( long long x, long long s[], int a ){
	int i = upper_bound(s, s+a, x) - s;
	long long res = 0x3f3f3f3f3f3f3f3f;
	if( i < a )
		res = min(res, s[i] - x);
	if( i > 0 )
		res = min(res, x - s[i-1]);
	return res;
}
long long solve( long long x, long long s[], long long a, long long t[], long long b ){
	int i = upper_bound(s, s+a, x) - s;
	long long res = 0x3f3f3f3f3f3f3f3f;
	if( i < a )
		res = min(res, s[i] - x + solve(s[i], t, b));
	if( i > 0 )
		res = min(res, x - s[i-1] + solve(s[i-1], t, b));
	return res;
}
int main(){
	scanf("%lld%lld%lld", &n, &m, &q);
	for( int i = 0; i < n; ++i )
		scanf("%lld", &a[i]);
	for( int j = 0; j < m; ++j )
		scanf("%lld", &b[j]);
	a[n] = b[m] = 0x3f3f3f3f3f3f3f3f;
	while( q-- ){
		long long x;
		scanf("%lld", &x);
		printf("%lld\n", min(solve(x, a, n, b, m), solve(x, b, m, a, n)));
	}
	return 0;
}