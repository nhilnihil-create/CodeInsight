#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

ll lcm(ll a, ll b){
   return a*b/gcd(a, b);
}


int main(){
	ll N, M;
	cin >> N >> M;	
	string S, T;
	cin >> S >> T;

	ll L = lcm(N, M);
	ll G = gcd(N, M);
	ll n = N/G;
	ll m = M/G;
	rep(i,G) {
		if (S[i*n] != T[i*m]) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << L << endl;
	return 0;
}
