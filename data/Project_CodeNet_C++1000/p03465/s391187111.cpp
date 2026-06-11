#include<bits/stdc++.h>
#define F first
#define S second
#define LL long long
#define PB push_back
#define MP make_pair
#define I insert

const LL N = 2002, mod = 1000000007;

using namespace std;

LL n, m, i, j, k, l, r, t, ans;
LL a[N];
bitset < 4000001 > b;

int main(){
	cin >> n;
	for ( i = 0; i < n; ++i ){
		cin >> a[i];
		k += a[i];
	}
	b[0] = 1;
	for ( i = 0; i < n; ++i ){
		b = (b|(b<<a[i]));
	}
	for ( i = (k+1) / 2; ; ++i ){
		if ( b[i] ){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
 
