#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

//aのb乗
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

//aの逆元
int gyakugen(int a){
	return beki(a,modulo-2);
}



int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	
	int gyaku = 1;
	for(int i=1;i<=N;i++){
		gyaku = mod(gyaku * i);
	}
	
	int ans = 0;
	
	int now = 0;
	
	for(int i=0;i<N;i++){
		now = mod(gyakugen(i+1)+now);
		int k = mod(A[i] * gyaku);
		k = mod(k*now);
		
		ans = mod(ans + k);
	}
	reverse(A.begin(),A.end());
	
	now=0;
	for(int i=0;i<N;i++){
		now = mod(gyakugen(i+1)+now);
		int k = mod(A[i] * gyaku);
		k = mod(k*now);
		
		ans = mod(ans + k);
	}
	
	for(int i=0;i<N;i++){
		ans = mod(ans - mod(gyaku * A[i]));
	}
	
	cout<<ans<<endl;
	
	
	
	
	return 0;
}

