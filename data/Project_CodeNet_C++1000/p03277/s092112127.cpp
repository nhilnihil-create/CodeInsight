#include<bits/stdc++.h>
#define F first
#define S second
#define LL long long
#define PB push_back
#define MP make_pair
#define I insert

const LL N = 2e5+5, mod = 1000000007;

using namespace std;

LL n, m, i, j, k, l, r, t, ans, nn;
LL a[N], b[N], c[N];
LL xe[N*3];

void upd ( LL x ) {
	while ( x <= N ) {
		xe[x]++;
		x += (x & -x);
	}
}
 
LL get ( LL x ) {
	LL k = 0;
	while ( x > 0 ) {
		k += xe[x];
		x -= (x & -x);
	}
	return k;
}

int main(){
	cin >> n;
	nn = 131072;
	for ( i = 0; i < n; ++i ){
		cin >> a[i];
		b[i] = a[i];
	}
	sort ( b, b + n );
	for ( LL ww = 18; ww >= 0; --ww ){
		k = ans + ( 1 << ww );
		if ( k >= n ) continue;
		t = n;
		for ( i = 0; i < n; ++i ){
			if ( a[i] >= b[k] ) c[i] = 1;
			else c[i] = -1;
			if ( i ) c[i] += c[i-1];
			if ( c[i] < t ) t = c[i];
		}
		t = 1 - t;
		for ( i = 0; i <= N; ++i ) xe[i] = 0;
		l = 0;
		for ( i = 0; i < n; ++i ){
			if ( c[i] >= 0 ) l++; 
			c[i] += t;
			l += get ( c[i] );
			upd ( c[i] );
			//cout << c[i] << " ";
		}
		//cout << endl;
		if ( l >= (1LL*n * (n+1) / 2 + 1) / 2 ) ans = k;
		//cout << k << " " << b[k] << " " << l << endl;
	}
	cout << b[ans] << endl;
	return 0;
}
 
/**/
//      IIIIIIIII      OOOOO             A          NN        N    EEEEEEEEEE
//          I         O     O           A A         N N       N    E
//          I        O       O         A   A        N  N      N    E
//          I        O       O        A     A       N   N     N    E
//          I        O       O       AAAAAAAAA      N    N    N    EEEEEEEE
//          I        O       O      A         A     N     N   N    E
//          I        O       O     A           A    N      N  N    E
//          I         O     O     A             A   N       N N    E
//      IIIIIIIII      OOOOO     A               A  N        NN    EEEEEEEEEE ___ KAPANADZE