#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000000 + 7;

int main(void){
	string s;
	cin >> s;
	long long all = 1, a = 0, ab = 0, abc = 0;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == 'A'){
			a += all;
		}
		if(s[i] == 'B'){
			ab += a;
		}
		if(s[i] == 'C'){
			abc += ab;
		}
		if(s[i] == '?'){
			abc = abc * 3 + ab;
			ab = ab * 3 + a;
			a = a * 3 + all;
			all *= 3;
		}
		all %= mod;
		a %= mod;
		ab %= mod;
		abc %= mod;
	}
	cout << abc << endl;
	return 0;
}