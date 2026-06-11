#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {

	string s;
	cin >> s;
	
	ll n = (ll)s.size();
	ll ans = 0, cnt = 0;
	rep(i,n) {
		if( s[i] == 'B' ){
          cnt++;
        }
		else {
          ans += cnt;
        }
	}
	
	cout<<ans<<endl;

	return 0;
}

