// D - Remainder Reminder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N,K; cin>>N>>K;

	if(K==0){ cout<< N*N <<endl; return 0; }

	ll cnt = 0;
	for(ll b=K+1; b<=N; ++b){
		ll p = N / b, r = N % b;
		cnt += p * max(0LL, b - K) + max(0LL, r - K + 1);
	}
	cout<< cnt <<endl;
}