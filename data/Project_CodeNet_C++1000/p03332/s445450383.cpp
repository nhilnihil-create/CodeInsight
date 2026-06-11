#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int jc[500003] , inv[500003];

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int binom(int a , int b){return a < b ? 0 : 1ll * jc[a] * inv[b] % MOD * inv[a - b] % MOD;}

int main(){
	long long N , A , B , K; cin >> N >> A >> B >> K;
	jc[0] = 1; for(int i = 1 ; i <= N ; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
	inv[N] = poww(jc[N] , MOD - 2); for(int i = N - 1 ; ~i ; --i) inv[i] = inv[i + 1] * (i + 1ll) % MOD;
	int sum = 0;
	for(long long i = 0 ; i <= N && i * A <= K ; ++i){
		if((K - i * A) % B) continue;
		long long t = (K - i * A) / B;
		sum = (sum + 1ll * binom(N , i) * binom(N , t)) % MOD;
	}
	cout << sum; return 0;
}