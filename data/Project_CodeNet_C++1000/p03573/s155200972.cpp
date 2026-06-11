#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	if (b==0) return a;
    else{
    	return gcd(b,a%b);
    }
}
 
int main() {
	ll a,b,c;
  	cin >> a >> b >> c;
	if(a==b){
      cout << c << endl;
    }
  	else if(a==c){
      cout << b << endl;
    }
  	else if(b==c){
      cout << a << endl;
      
    }
}
