#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long modpow(long long a, long long b){
	a %= MOD;
	long long res = 1;
	while (b > 0){
		if (b % 2 == 1) res = res * a % MOD;
		a = a * a % MOD;
		b = b / 2;
	}
	return res;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<long long> mf;
long long modfact(long long n){
	if (n < mf.size()){
		return mf[n];
	} else {
		if (mf.empty()) mf.push_back(1);
		long long res = mf.back();
		for (int i = mf.size(); i <= n; i++){
			res = res * i % MOD;
			mf.push_back(res);
		}
		return res;
	}
}
long long modbinom(long long n, long long r){
	long long res;
	res = modfact(n);
	res = res * modinv(modfact(r)) % MOD;
	res = res * modinv(modfact(n - r)) % MOD ;
	return res;
}
int main(){
  long long N, A, B, K;
  cin >> N >> A >> B >> K;
  long long ans = 0;
  for (int i = 0; i <= N; i++){
    long long R = (K - A * i);
    if (R % B != 0){
      continue;
    }
    long long j = R / B;
    if (j < 0 || j > N){
      continue;
    }
    ans = (ans + modbinom(N, i) * modbinom(N, j) % MOD) % MOD;
  }
  cout << ans << endl;
}