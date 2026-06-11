#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int dsum( int x ){
	int res = 0;
	while( x > 0 ){
		res += x%10;
		x /= 10;
	}
	return res;
}

int main(){
	int n; cin >> n;
	int ans = inf;
	for( int a = 1; a < n; ++a ){
		int b = n-a;
		ans = min(ans, dsum(a)+dsum(b));
	}
	cout << ans << endl;
}