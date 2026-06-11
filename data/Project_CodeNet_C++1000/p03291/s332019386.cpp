#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair

#define MOD (LL)(1e9+7)

//累乗 O(log N)
long long power(long long x, long long N){
	if(N == 0) return 1LL;
	if(N == 1) return x;
	long long tmp = power(x, N/2);
	if(N%2 == 0) return tmp * tmp % MOD;
	else return tmp * tmp % MOD * x % MOD;
}

string S;
LL waA[100001]={}, waC[100001]={}, waQ[100001]={};

int main(){
	cin >> S;
	for(int i=0; i<S.size(); i++){
		waA[i+1] = waA[i];
		waC[i+1] = waC[i];
		waQ[i+1] = waQ[i];
		if(S[i] == 'A') waA[i+1]++;
		if(S[i] == 'C') waC[i+1]++;
		if(S[i] == '?') waQ[i+1]++;
	}

	LL ans = 0;
	for(int i=0; i<S.size(); i++){
		if(S[i] == 'B'){
			ans += waA[i] * (waC[S.size()] - waC[i+1]) % MOD * power(3, waQ[S.size()]);
			ans += waQ[i] * (waC[S.size()] - waC[i+1]) % MOD * power(3, waQ[S.size()]-1);
			ans += waA[i] * (waQ[S.size()] - waQ[i+1]) % MOD * power(3, waQ[S.size()]-1);
			ans += waQ[i] * (waQ[S.size()] - waQ[i+1]) % MOD * power(3, waQ[S.size()]-2);
			ans %= MOD;
		}
		if(S[i] == '?'){
			ans += waA[i] * (waC[S.size()] - waC[i+1]) % MOD * power(3, waQ[S.size()]-1);
			ans += waQ[i] * (waC[S.size()] - waC[i+1]) % MOD * power(3, waQ[S.size()]-2);
			ans += waA[i] * (waQ[S.size()] - waQ[i+1]) % MOD * power(3, waQ[S.size()]-2);
			ans += waQ[i] * (waQ[S.size()] - waQ[i+1]) % MOD * power(3, waQ[S.size()]-3);
			ans %= MOD;
		}
	}
	cout << ans << endl;
}