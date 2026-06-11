// D - Remainder Reminder
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int N,K; cin>>N>>K;

	if(K==0){
		cout<< (ll)N*N <<endl;
		return 0;
	}

	ll cnt = 0;
	for(int b=K+1; b<=N; ++b){
		int p = N/b;
		int r = N%b;
		cnt += p * max(0, b-K);
		cnt += max(0, r-K+1);
	}
	cout<< cnt <<endl;
}