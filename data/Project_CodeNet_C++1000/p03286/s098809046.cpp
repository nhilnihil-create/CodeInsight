#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s="";
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	while(n!=0){
		if(n%2==0){
			s+='0';
			n=n/-2;
		}
		else if(n%2!=0){
			s+='1';
			n=(n-1)/-2;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}