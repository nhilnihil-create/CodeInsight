#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	ll a = 0, b = 0, c = 0, a_ = 0, b_ = 0, c_ = 0;
	string s; cin >> s;
	ll cnt = 1;
	for( char t : s ){
		if( t == 'A' ) a += cnt;
		else if( t == 'B' ) b += a;
		else if( t == 'C' ) c += b;
		else {
			c *= 3;
			c += b;
			b *= 3;
			b += a;
			a = a*3+cnt;
			cnt *= 3;
		}
		a %= mod; b %= mod; c %= mod; cnt %= mod;
	}
	cout << c << endl;
}