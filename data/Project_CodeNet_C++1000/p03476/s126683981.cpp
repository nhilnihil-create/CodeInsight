#include <bits/stdc++.h>


using namespace std;

#define ll long long

bool isprime(ll n) {
	if(n<=1) return 0;
	for(ll x=2;x*x<=n;x++) if(n%x==0) return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Q;
	cin >> Q;
	ll MAX=2e5;
	vector<ll> s(MAX);
	for(ll i=1;i<MAX;i++) {
		s[i]=s[i-1]+((i&1)&&isprime(i)&&isprime((i+1)/2));
	}
	while(Q--) {
	   ll l,r;
	   cin >> l >> r;
	   cout << s[r] - s[l-1] << "\n";
	}
   return 0;
}


