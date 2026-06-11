#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	string S;
	cin>>S;
	
	if(S.size()>=10){
		cout<<"NO"<<endl;
		return 0;
	}
	
	for(int i=0;i<(1<<(S.size()+1));i++){
		string X = "";
		
		for(int j=0;j<S.size();j++){
			if((1<<j)&i){
				X += 'A';
			}
			X += S[j];
		}
		
		if((1<<S.size())&i)X += 'A';
		
		if(X=="AKIHABARA"){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	
	return 0;
}