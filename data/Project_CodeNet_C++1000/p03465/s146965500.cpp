#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	int S = 0;
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		S += A[i];
	}
	
	
	bitset<4000001> B;
	B[0] = true;
	
	for(int i=0;i<N;i++){
		B |= (B<<A[i]);
	}
	
	int k = (S+1)/2;
	
	for(int i=k;true;k++){
		if(B[k]){
			cout<<k<<endl;
			return 0;
		}
	}

	return 0;
}