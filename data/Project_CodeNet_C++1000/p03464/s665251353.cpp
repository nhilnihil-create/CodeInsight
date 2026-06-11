#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000


int main(){
	
	int K;
	cin>>K;
	
	vector<long long> A(K);
	for(int i=0;i<K;i++){
		cin>>A[i];
	}
	
	long long ok1 = Inf;
	long long ng1 = 0;
	
	while(ok1-ng1>1){
		long long mid = (ok1+ng1)/2;
		long long k = mid;
		for(int i=0;i<K;i++){
			k = (k/A[i])*A[i];
		}
		if(k>=2)ok1=mid;
		else ng1=mid;
	}
	
	long long ok2 = 0;
	long long ng2 = Inf;
	
	while(ng2-ok2>1){
		long long mid = (ok2+ng2)/2;
		long long k = mid;
		for(int i=0;i<K;i++){
			k = (k/A[i])*A[i];
		}
		if(k>2)ng2=mid;
		else ok2=mid;
	}
	
	if(ok2>=ok1){
		cout<<ok1<<' '<<ok2<<endl;
	}
	else{
		cout<<-1<<endl;
	}
		
	
	return 0;
	
}
