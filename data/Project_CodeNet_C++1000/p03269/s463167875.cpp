#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int L;
	cin>>L;
	int D = L;
	
	vector<vector<pair<int,int>>> E(1,vector<pair<int,int>>());
	for(int i=0;i<20;i++){
		E.push_back(vector<pair<int,int>>());
		if((1<<i)<L){
			L-=(1<<i);
			E[i].emplace_back(i+1,(1<<i));
			E[i].emplace_back(i+1,0);
		}
		else{
			E.pop_back();
			break;
		}
	}

	for(int i=E.size()-2;i>=0;i--){
		int t = (1<<i);
		if(L>t){
			E[i].emplace_back(E.size()-1,D-L+1);
			L-=t;
		}
	}
	
	int N = E.size();
	int M = 0;
	for(int i=0;i<N;i++)M += E[i].size();
	cout<<N<<' '<<M<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<E[i].size();j++){
			cout<<i+1<<' '<<E[i][j].first+1<<' '<<E[i][j].second<<endl;
		}
	}
	
	return 0;
}