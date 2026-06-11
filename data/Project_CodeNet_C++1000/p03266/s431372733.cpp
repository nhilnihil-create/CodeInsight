// C - Triangular Relationship
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K; cin>>N>>K;
	long long ans = 0;
	int q = N/K, r = N%K;
	for(int a=1; a<=N; ++a){
		int b = K - a%K, c = K - b%K;
		if((c + a)%K == 0){
			long long now = 1;
			now *= (1<=b%K && b%K<=r)? q+1: q;
			now *= (1<=c%K && c%K<=r)? q+1: q;
			ans += now;
		}
	}
	cout<< ans <<endl;
}
