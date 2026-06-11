#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int impossible(){
	cout << -1 << endl;
	return 0;
}

int main(){
	int n; cin >> n;
	vector<ll> a(n);
	for( auto &k : a ) cin >> k;
	reverse( a.begin(), a.end() );
	ll ans = 0;
	for( int i = 0; i < n-1; ++i ){
		if( a[i] - a[i+1] > 1 ) return impossible();
		if( a[i] <= a[i+1] ) ans += a[i];
		else if( a[i] != 0 ) ++ans;
	}
	if( a[n-1] != 0 ) return impossible();
	cout << ans << endl;
	/*
	for( int i = 1; i < n; ++i ){
		if( i == 1 ){
			if( a[i-1] < a[i] ) ans += a[i-1];
			else if( a[i-1] != 0 ) ++ans;
		}
		if( ( i == n-1 and a[i] != 0 ) or a[i-1] - a[i] > 1 ) return impossible();
		else if( a[i-1] == a[i] ) ans += a[i];
		else if( a[i] != 0 ) ++ans;
	}
	*/
}

