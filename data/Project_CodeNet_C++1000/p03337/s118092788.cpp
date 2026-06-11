#include<iostream>
#include<cmath>
using namespace std; 
int a,b,c,d,sum;
int main(){
	cin>>a>>b;
	c=a*b;
	d=a+b;
	sum=a-b;
	c=fmax(c,d);
	cout<<fmax(sum,c);
	
}