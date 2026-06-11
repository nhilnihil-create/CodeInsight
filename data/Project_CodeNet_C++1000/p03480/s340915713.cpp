#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	string s; cin >> s;
 	int n = s.l_ength();
	int l = 0, r = n-1;
	int a = 0, b = n;
	while( l < r ){
		if( s[l] != s[l+1] ) a = l+1;
		if( s[r-1] != s[r] ) b = r;
		++l; --r;
	}
	cout << min( n-a, b ) << endl;
}