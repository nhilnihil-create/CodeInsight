#include<iostream>
using namespace std; 
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a<=b){
		if(c<=d){
			cout<<a+c;	
		}
		else{
			cout<<a+d;
		}
	}
	else{
		if(c<=d){
		cout<<b+c;	
		}
		else{
			cout<<b+d;
		}
	}
}