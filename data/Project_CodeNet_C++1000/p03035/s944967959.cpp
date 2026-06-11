#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	if(a<=5)
		cout<<0;
	else if(a>=6 && a<=12)
		cout<<b/2;
	else 
		cout<<b;
	return 0;
}