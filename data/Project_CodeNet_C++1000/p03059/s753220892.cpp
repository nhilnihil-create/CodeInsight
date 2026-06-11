#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,x,k=0;
	cin>>a>>b>>x;
	x+=0.5;
	while(a<=x){
		k+=b;
		x-=a;	
	}
	cout<<k;
}