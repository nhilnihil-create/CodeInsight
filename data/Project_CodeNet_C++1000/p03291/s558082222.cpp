#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;

template <class T>
using lim = numeric_limits<T>;

const int MOD = 1'000'000'007;
int main() {
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	
	// tracks possibilities 3^(# of ?)
	ll possible = 1;
	
	// how many c's, bc's, and abc's
	ll abc = 0;
	ll bc = 0;
	ll c = 0;
	
	for (int i = n-1; i >= 0; i--){
		if (s[i] == '?'){
			// math
			abc = (abc*3 + bc)%MOD;
			bc = (bc*3 + c)%MOD;
			c = (c*3 + possible)%MOD;
			
			possible = (possible*3)%MOD;
		}
		else if (s[i] == 'C') c = (c+possible)%MOD;
		else if (s[i] == 'B') bc = (bc+c)%MOD;
		else abc = (abc+bc)%MOD;
	}
	
	cout << abc << endl;
}

