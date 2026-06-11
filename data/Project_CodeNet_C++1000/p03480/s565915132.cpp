#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	string s; cin >> s;
 	int n = s.l_ength();
  	int ans = n;
	for( int i = 0; i < n-1; ++i ){
		if( s[i] != s[i+1] ){
			ans = min(ans, max(i+1, n-i-1));
		}
	}
	cout << ans << endl;
}