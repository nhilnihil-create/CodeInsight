#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int N;
	cin>>N;
	
	vector<long long> L(N),R(N);
	
	for(int i=0;i<N;i++){
		cin>>L[i]>>R[i];
		L[i]*=2;
		R[i]*=-2;
	}
	
	sort(L.begin(),L.end(),greater<long long>());
	sort(R.begin(),R.end(),greater<long long>());
	
	long long ans = 0;
	long long now = 0;
	for(int i=0;i<N;i++){
		now += L[i];
		ans = max(ans,now);
		now += R[i];
		ans = max(ans,now);
	}
	
	now = 0;
	
	for(int i=0;i<N;i++){
		now += R[i];
		ans = max(ans,now);
		now += L[i];
		ans = max(ans,now);
	}
	
	cout<<ans<<endl;


	return 0;
}