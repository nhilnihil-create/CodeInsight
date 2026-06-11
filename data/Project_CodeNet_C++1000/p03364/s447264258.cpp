#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

bool check(vector<string> &V){
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V.size();j++){
			if(V[i][j]!=V[j][i])return false;
		}
	}
	return true;
}

int main(){

	int N;
	cin>>N;
	
	vector<string> V(N);
	
	for(int i=0;i<N;i++){
		cin>>V[i];
	}
	
	int ans = 0;
	
	for(int i=0;i<N;i++){
		if(check(V))ans+=N;
		
		V.push_back(V[0]);
		V.erase(V.begin());
	}
	
	cout<<ans<<endl;
	
	
	
	return 0;
}