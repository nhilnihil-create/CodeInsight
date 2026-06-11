#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000


int main(){
	
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	
	int mini = 0;
	int ind = 0;
	
	for(int i=0;i<N;i++){
		if(abs(mini)<abs(a[i])){
			mini = a[i];
			ind = i;
		}
	}
	
	cout<<N-1+N-1<<endl;
	
	for(int i=0;i<N;i++){
		if(i==ind)continue;
		cout<<ind+1<<' '<<i+1<<endl;
	}
	
	if(mini>=0){
		for(int i=0;i<N-1;i++){
			cout<<i+1<<' '<<i+2<<endl;
		}
	}
	else{
		for(int i=N-1;i>=1;i--){
			cout<<i+1<<' '<<i<<endl;
		}
	}
	
    return 0;
}
