#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 //Compiler version g++ 6.3.0

 int main()
 {
 	ll n, p;
 	cin >> n >> p;
 	if(n == 1){
 		cout << p << endl;
 	} else {
 		ll i = 1000000;
 		while(1){
 			ll power = pow(i, n);
 			if(p % power == 0) break;
 			i--;
 		}
 		cout << i << endl;
 	}
 	
 	return 0;
 }