#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

ll pitta[60], smaller[60];

const int shift = 50;

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	for( auto &t : a ) cin >> t;
	for( int d = 0; d < shift; ++d ){
		ll mask = (1ll<<(shift-1-d));
		ll cnt = 0;
		for( auto &t : a ){
			if( t & mask ) ++cnt;
		}
		pitta[d+1] = pitta[d] + ( ( k & mask ) ? (n-cnt) : (cnt) ) * mask;
		if(	smaller[d] > 0 ) smaller[d+1] = smaller[d] + max(cnt, n-cnt)*mask;
		if( k & mask ) smaller[d+1] = max( smaller[d+1], pitta[d] + cnt*mask );
	}
	cout << max(pitta[shift], smaller[shift]) << endl;
}