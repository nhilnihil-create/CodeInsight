#include<iostream>
#include<cmath>
using namespace std; 
int a,b,c,d,sum1=0,x=0,sum2=0;
int main(){
	cin>>a>>b>>c>>d;
	sum1=abs(a-b);
	sum2=abs(b-c);
	x=x+abs(a-c);
	if(x<=d){
		cout<<"Yes"	;
	}
	else if(sum1<=d && sum2<=d){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	

}