#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N;
	cin>>N;
	
	string S;
	
	cout<<0<<endl;
	cin>>S;
	
	if(S=="Vacant"){
		return 0;
	}
	
	int ok = 0;
	int ng = N;
	
	
	while(true){
		int mid = (ok+ng)/2;
		string T;
		cout<<mid<<endl;
		cin>>T;
		
		if(T=="Vacant"){
			return 0;
		}
		
		if((T==S) == (mid%2==0)){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	
	return 0;
}