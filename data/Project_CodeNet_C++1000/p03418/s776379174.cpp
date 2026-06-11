#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	long long N,K;
	cin >> N >> K;

	if(K==0){
		cout << N*N << endl;
		return 0;
	}

	long long ans=0;
	for(int b=1;b<=N;b++){
		if(b<K+1)	continue;
		long long x=N/b;
		long long y=N%b;
		ans+=x*(b-K);
		ans+=max((long long)0,y-K+1);
	}
	cout << ans << endl;

	return 0;
}
