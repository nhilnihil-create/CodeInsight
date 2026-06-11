#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int N;
	cin>>N;
	
	vector<int> P(N);
	vector<int> ind(N);
	for(int i=0;i<N;i++){
		cin>>P[i];
		P[i]--;
		ind[P[i]] = i;
	}
	
	vector<int> K(N,0);
	
	for(int i=0;i<N;i++){
		if(i!=0&&ind[i] > ind[i-1]){
			K[i] = K[i-1] + 1;
		}
		else{
			K[i] = 1;
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<N;i++){
		ans = max(ans,K[i]);
	}
	
	cout<<N-ans<<endl;
	
    return 0;
}