#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int BIG = 1e9 + 555;
const int maxN = 1e5 + 55;

int n;
ll fact[maxN], rev[maxN];

ll quickPow(ll x, ll y){
	if(y == 0){
		return 1;
	}

	ll tmp = quickPow(x, y / 2);
	if(y % 2){
		return (((tmp * tmp) % MOD) * (x % MOD)) % MOD;
	}

	return (tmp * tmp) % MOD;
}

void preCal(){
	fact[0] = 1;
	for(int i = 1; i < maxN; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	
	
	for(int i = 1; i < maxN; i++){
		rev[i] = quickPow(i, MOD - 2);
	}

	for(int i = 1; i < maxN; i++){
		rev[i] = (rev[i] + rev[i - 1]) % MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	preCal();

	cin >> n;
	
	ll fRes = 0;

	for(int i = 1; i <= n; i++){
		ll x;	cin >> x;
		ll rt = (((rev[i] + rev[n - i + 1]) % MOD) - 1 + MOD) % MOD;
		
		rt = (fact[n] * rt) % MOD;

		fRes = (fRes + ((x * rt) % MOD)) % MOD;
	}
	
	cout << fRes << '\n';

	return 0;
}