#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int old,k;
int main(){
	cin>>old>>k;
	if(old<6){
		cout<<0;
	}
	else if(old<13){
		cout<<k/2;	
	}
	else{
		cout<<k;
	}
}