#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int N,K;
	cin>>N>>K;
	
	long long ans = 0;
	
	for(int i=K+1;i<=N;i++){
		int a = i-K;
		int b = N/i;
		ans += (long long) a*b;
		if(K!=0)ans += (long long)max(0,(N%i)+1-K);
		else ans+=(long long)(N%i);
	}
	
	cout<<ans<<endl;
		
    return 0;
}
