#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,y;
	cin>>n>>y;
 
	bool ans=false;
 
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			int k=n-i-j;
			int maney=i*10000+j*5000+k*1000;
			if(y==maney){
				ans=true;
				cout<<i<<' '<<j<<' '<<k<<endl;
				break;
			}
		}
		if(ans) break;
	}
 
	if(!ans){
		cout<<-1<<' '<<-1<<' '<<-1<<endl;
	}
 
	return 0;
}