// D - Remainder Reminder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll N,K; cin>>N>>K;
	ll cnt = 0, d = K!=0;
	for(ll b=K+1; b<=N; ++b) cnt += N/b * max(0LL, b-K) + max(0LL, N%b-K + d);
	cout<< cnt <<endl;
}