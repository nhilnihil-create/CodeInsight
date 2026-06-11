#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int yes(){
	cout << "YES" << endl;
	return 0;
}

int no(){
	cout << "NO" << endl;
	return 0;
} 

int main(){
	string s; cin >> s;
	if( s.l_ength() == 1 || s == "ab" || s == "bc" || s == "ca" || s == "ba" || s == "cb" || s == "ac" ) return yes();
	map<char, int> mp;
	for( char k : s ) ++mp[k];
	int a = mp['a'], b = mp['b'], c = mp['c'];
	if( a == 0 || b == 0 || c == 0 ) return no();
	int m = min({a, b, c});
	a -= m;
	b -= m;
	c -= m;
	if( a <= 1 && b <= 1 && c <= 1 ) return yes(); 
	return no();
}