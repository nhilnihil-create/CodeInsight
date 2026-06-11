#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,t,custo,tempo,min=1001;
	
	cin>>n>>t;

	while(n--){
		cin>>custo>>tempo;
		if(tempo<=t){
			if(min>custo){
				min=custo;
			}
		}
	}

	if(min>1000)
		cout<<"TLE"<<endl;
	else
		cout<<min<<endl;

	return 0;
}