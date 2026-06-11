#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int N;
	cin>>N;
	
	long long X;
	cin>>X;
	
	vector<long long> x(N);
	for(int i=0;i<N;i++)cin>>x[i];
	
	vector<long long> S(N+1,0);
	for(int i=0;i<N;i++){
		S[i+1] = x[i];
		S[i+1] += S[i];
	}
	
	long long ans = Inf;
	
	for(int i=1;i<=N;i++){
		long long t = X*i;
		t += S[N] - S[N-i];
		long long p = 2;
		long long now = 4;
		for(int j=N;j>=1;j-=i){
			if(j-i>=0)t += now * (S[j] - S[j-i]);
			else t += now*S[j];
			if(t>=Inf)break;
			p++;
			now = p*p - (p-1)*(p-1);
		}

		ans = min(ans,t);
	}
	
	cout<<ans+X*N<<endl;
	
	return 0;
}
