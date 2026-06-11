#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){
    
	int N;
	cin>>N;
	
	if(N==3){
		cout<<"2 5 63"<<endl;
		return 0;
	}
	
	vector<int> V;
	for(int i=1;i<=30000;i++){
		if(i%2==0||i%3==0){
			V.push_back(i);
		}
	}
	
	int sum = 0;
	int now = 0;
	
	for(int i=0;i<N-2;i++){
		if(i!=0)cout<<' ';
		cout<<V[i];
		sum += V[i];
	}
	
	for(int i=N-2;i<V.size();i++){
		for(int j=i+1;j<V.size();j++){
			if((sum+V[i]+V[j])%6==0){
				cout<<' '<<V[i]<<' '<<V[j]<<endl;
				return 0;
			}
		}
	}
	
    return 0;
}

