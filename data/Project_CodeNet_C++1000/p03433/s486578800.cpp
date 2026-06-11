#include<iostream>
using namespace std; 
int main(){
	int a,b,c;
	cin>>c>>a;
	while(c>=500){
		c-=500;
	}
	if(c<=a){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}

}