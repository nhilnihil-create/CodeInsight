#include<iostream>

using namespace std;

int main(){
	int p[8]={3,5,7,11,13,17,19,23};
	int n;cin>>n;
	int ans=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			for(int k=j+1;k<8;k++){
				int temp=p[i]*p[j]*p[k];
				if(temp<=n){ans++;}
				else{break;}
			}
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
				if(i==j){continue;}
				int temp=p[i]*p[i]*p[i]*p[j];
				if(temp<=n){ans++;}
				else{break;}
		}
	}
	cout<<ans<<endl;
}
