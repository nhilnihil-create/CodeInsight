#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a*a+b*b==c*c)cout<<a*b/2<<endl;
	else if(b*b+c*c==a*a)cout<<b*c/2<<endl;
	else cout<<c*a/2<<endl;
	return 0;
}