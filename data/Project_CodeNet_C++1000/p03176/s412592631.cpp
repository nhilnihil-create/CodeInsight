#include<bits/stdc++.h>
#define LLI long long int
#define ULTRA 2134567890
using namespace std;

struct SGT {
	LLI tree[1000007] = {};
	
	int LC( int i) { return i*2;}
	int RC( int i) { return i*2+1;}
	
	void pull( int i) {
		tree[i] = max( tree[LC(i)], tree[RC(i)]);
	}
	void upd( int x, LLI d, int l, int r, int i=1) {
		if( l == r) {
			tree[i] = d;
			return;
		}
		
		int m = ( l + r ) / 2;
		if( x <= m)
			upd( x, d, l, m, LC(i));
		if( m+1 <= x)
			upd( x, d, m+1, r, RC(i));
		pull(i);
	}
	LLI query( int x1, int x2, int l, int r, int i=1) {
		if( x1 <= l && r <= x2) {
			return tree[i];
		}
		int m = ( l + r ) / 2;
		LLI ans = 0;
		if( x1 <= m)
			ans = max( ans, query( x1, x2, l, m, LC(i)));
		if( m+1 <= x2)
			ans = max( ans, query( x1, x2,m+1, r, RC(i)));
		return ans;
	}
}dp;

int h[200007] = {};
int a[200007] = {};

int main() {
	
	int i,j;
	int N;
	
	cin >> N;
	for( i=1; i<=N; i++)
		cin >> h[i];
	for( i=1; i<=N; i++)
		cin >> a[i];
		
	for( i=1; i<=N; i++) {
		LLI q = dp.query( 0, h[i]-1, 0, N);
//		printf(">>> %lld\n", q);
		dp.upd( h[i], q + a[i], 0, N);
	}
	
//	while(1) {
//		int l,r;
//		scanf("%d %d", &l, &r);
//		LLI q = dp.query( l, r, 0, N);
//		printf("%lld\n", q);
//	}
	
	LLI ans = dp.query( 0, N, 0, N);
	printf("%lld\n", ans);
	
	return 0;
} 