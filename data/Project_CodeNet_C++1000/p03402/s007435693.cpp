#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int A,B;
	cin>>A>>B;
	A--;B--;
	
	vector<string> V(100,"");
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(i<50)V[i]+='.';
			else V[i]+='#';
		}
	}
	
	cout<<"100 100"<<endl;
	
	for(int i=0;i<100;i+=2){
		for(int j=0;j<100;j+=2){
			if(B==0)break;
			B--;
			V[i][j]='#';
		}
	}
	
	for(int i=51;i<100;i+=2){
		for(int j=0;j<100;j+=2){
			if(A==0)break;
			A--;
			V[i][j]='.';
		}
	}
	
	for(int i=0;i<100;i++)cout<<V[i]<<endl;
		
    return 0;
}
