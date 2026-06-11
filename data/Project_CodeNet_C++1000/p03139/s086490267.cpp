///who is the king ??? *** << t.mohammad >> *** ///
/*
                  00                                                                                                            00
                 00                               00                                                                           00
            0000000000                           00                                                                           00
           0000000000   000       000           00                        000       000  000       000                       00
              00       0000     0000           00         000000         0000     0000  0000     0000   000000              00
             00       00 00   00 00    000    00        00000000        00 00   00 00  00 00   00 00  00000000       00000000
            00       00  00 00  00   00000   000000    00    000       00  00 00  00  00  00 00  00  00    000     0000000000
           00       00   000   00  00   00  00000000  00    0000      00   000   00  00   000   00  00    0000    00     0000
          00       00         00  00   00  00    00  00    00 00     00         00  00         00  00    00 00   00     00 00
         00  00   00         00   00000   00    00  00000000  00    00         00  00         00  00000000  00  000000000  00
        00  00   00         00    000    00    00   000000    00   00         00  00         00   000000    00  0000000    00
*/
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;
typedef long double dou ;
typedef pair<ll , ll> pii;
typedef map<ll, bool> mib;
typedef pair<ll, bool> pib;
typedef map<ll , ll> mii;
#define wh while
#define str string
#define vec vector
#define fori(a1 , a2 , a3) for(ll i = a1 ; i < a2 ; i = i + a3)
#define for_i(b1 , b2 , b3) for(ll i = b1 ; i >= b2 ; i = i - b3)
#define forj(c1 , c2 , c3) for(ll j = c1 ; j < c2 ; j = j + c3)
#define for_j(d1 , d2 , d3) for(ll j = d1 ; j >= d2 ; j = j - d3)
#define fore(e1 , e2 , e3) for(ll e = e1 ; e < e2 ; e = e + e3)
#define for_e(f1 , f2 , f3) for(ll e = f1 ; e >= f2 ; e = e - f3)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define fast ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
#define setp(t) cout << setprecision(t) << fixed ;
int main(){
	fast ;
	ll n , a , b ;
	cin >> n >> a >> b ;
	cout << min(a , b) << " " ;
	ll c = a + b ;
	if (n - c < 0)
	{
		cout << abs(n - c) ;
		return 0 ;
	}
	cout << 0 ;
	
}


