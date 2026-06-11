#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int ans=0;
	
	if(b<=c){
		c-=b;
		ans=ans+(b*2);
		b=0;
		
	}
	else
	{
		ans=ans+b+c;
		c=0;
		b=0;
	}
	if(c<=a+1){
		ans+=c;
		
		
	}
	else
	{
		
		ans=ans+a+1;
	}
	cout<<ans<<endl;
}