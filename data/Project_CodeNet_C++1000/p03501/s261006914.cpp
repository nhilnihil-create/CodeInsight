#include<iostream>
using namespace std;
int main(){
	int a,b,c,x; 
	cin>>a>>b>>c;
	x=a*b;
	if(x<c){
		cout<<x;
	}
	else{
		cout<<c;
	}
}