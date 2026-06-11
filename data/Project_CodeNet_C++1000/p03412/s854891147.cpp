
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 3e5+66;
LL a[AX];
LL b[AX];
LL c[AX];
int n ;	
 
LL Binary(LL k)
{
    int l = 1 , r = n + 1;
    while( l < r ){
        int mid = ( l + r ) >> 1;
        if(c[mid] >= k) r = mid ; 
        else l = mid + 1 ;
    }
    return l;
}
 
int main(){
	//freopen("pp.in", "r", stdin);
	//freopen("std.out", "w", stdout);
	cin >> n ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	for( int i = 1 ; i <= n ; i++ ){
		cin >> b[i];
	}
	LL res = 0 ;
	for( int k = 1 ; k <= 29 ; k ++ ){
		LL tmp = (1<<k) - 1;
		for( int i = 1 ; i <= n ; i++ ){
			c[i] = b[i] & tmp;
		}
		LL cnt = 0;
		sort( c + 1, c + n + 1 );
		for( int i = 1 ; i <= n ; i++ ){
			cnt += n - Binary( ( (1<<(k-1)) -(tmp & a[i]) ) )+1;
		}
		for( int i = 1 ; i <= n ; i++ ){
			cnt -= Binary( (1<<k)+(1<<(k-1))-(tmp&a[i])) - Binary((1<<k)-(tmp&a[i]));
		}
		if( cnt & 1 ) res += (1<<(k-1));
	}
	cout << res << endl;
	return 0 ;
}