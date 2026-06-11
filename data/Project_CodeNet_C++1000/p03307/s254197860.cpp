#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
double delta(ll x){
	ll c = x, s = 0;
	while( c> 0){
	 	s += c%10; c/= 10;
	}
	return (double)1.0*x/s;
}
int main(){
	int n; cin >> n;
	if(n&1)cout << n*2 << endl;
	else cout << n << endl;
	return 0;
}                  
