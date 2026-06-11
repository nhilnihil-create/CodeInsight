#include<bits/stdc++.h>
using namespace std;
long long f(long long n){
	long long ret = 0;
	long long unit = 1;
	while(unit<=n){
		long long div = unit*2;
		long long division = n/div; 
		long long left = n%div; 
		left++;
		long long parity = max(left-unit,(long long)0);
		if(unit==1) parity+=division;
		if(parity%2) ret|=unit;
		unit*=2;
	}	
	return ret;
}

int main(){
	long long a,b;
	cin>>a>>b;
	cout<<(f(b)^f(a-1));
}