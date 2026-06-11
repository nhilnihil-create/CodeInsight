#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	int M,K;
	cin>>M>>K;
	
	if((1<<M)<=K){
		cout<<-1<<endl;
		return 0;
	}
	
	if(M==1&&K==1){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> ans;
	
	if(K==0){
		for(int i=0;i<(1<<M);i++){
			ans.push_back(i);
			ans.push_back(i);
		}
	}
	else{
		for(int i=0;i<(1<<M);i++){
			if(i==K)continue;
			ans.push_back(i);
		}
		ans.push_back(K);
		for(int i=(1<<M)-1;i>=0;i--){
			if(i==K)continue;
			ans.push_back(i);
		}
		ans.push_back(K);
	}
	
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}