#include <bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(ll i=0;i<n;i++)
using namespace std;

const int mod = 1e9+7;
const int N = 10000003;
int prime[N];
unordered_map <ll, ll> max_map;

ll power(ll x, ll y){
	x %= mod;
	if(y == 0) return 1;
	if(y == 1) return x;
	ll num = power(x,y/2) % mod;
	if(y%2 ==  0) return (num*num)%mod;
	else return (((num*num)%mod)*x)%mod;
}

void solve(){
 	
 	int d;
 	cin >> d;
 	if(d == 25) cout << "Christmas";
 	if(d == 24) cout << "Christmas Eve";
 	if(d == 23) cout << "Christmas Eve Eve";
 	if(d == 22) cout << "Christmas Eve Eve Eve";

	return;
}


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		solve();
		// cout << "\n";
	}

	// cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

	return 0; 
}